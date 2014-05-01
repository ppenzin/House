%
% (c) The GRASP/AQUA Project, Glasgow University, 1998
%
\section[NameSet]{@NameSets@} 

\begin{code}
module NameSet (
	-- Sets of Names
	NameSet,
	emptyNameSet, unitNameSet, mkNameSet, unionNameSets, unionManyNameSets,
	minusNameSet, elemNameSet, nameSetToList, addOneToNameSet, addListToNameSet, 
	delFromNameSet, delListFromNameSet, isEmptyNameSet, foldNameSet, filterNameSet,
	intersectsNameSet, intersectNameSet,
	
	-- Free variables
	FreeVars, isEmptyFVs, emptyFVs, plusFVs, plusFV, 
	mkFVs, addOneFV, unitFV, delFV, delFVs,

	-- Defs and uses
	Defs, Uses, DefUse, DefUses,
	emptyDUs, usesOnly, mkDUs, plusDU, 
	findUses, duDefs, duUses
    ) where

#include "HsVersions.h"

import Name
import UniqSet
\end{code}


%************************************************************************
%*									*
\subsection[Sets of names}
%*									*
%************************************************************************

\begin{code}
type NameSet = UniqSet Name
emptyNameSet	   :: NameSet
unitNameSet	   :: Name -> NameSet
addListToNameSet   :: NameSet -> [Name] -> NameSet
addOneToNameSet    :: NameSet -> Name -> NameSet
mkNameSet          :: [Name] -> NameSet
unionNameSets	   :: NameSet -> NameSet -> NameSet
unionManyNameSets  :: [NameSet] -> NameSet
minusNameSet 	   :: NameSet -> NameSet -> NameSet
elemNameSet	   :: Name -> NameSet -> Bool
nameSetToList	   :: NameSet -> [Name]
isEmptyNameSet	   :: NameSet -> Bool
delFromNameSet	   :: NameSet -> Name -> NameSet
delListFromNameSet :: NameSet -> [Name] -> NameSet
foldNameSet	   :: (Name -> b -> b) -> b -> NameSet -> b
filterNameSet	   :: (Name -> Bool) -> NameSet -> NameSet
intersectNameSet   :: NameSet -> NameSet -> NameSet
intersectsNameSet  :: NameSet -> NameSet -> Bool 	-- True if non-empty intersection
	-- (s1 `intersectsVarSet` s2) doesn't compute s2 if s1 is empty

isEmptyNameSet    = isEmptyUniqSet
emptyNameSet	  = emptyUniqSet
unitNameSet	  = unitUniqSet
mkNameSet         = mkUniqSet
addListToNameSet  = addListToUniqSet
addOneToNameSet	  = addOneToUniqSet
unionNameSets     = unionUniqSets
unionManyNameSets = unionManyUniqSets
minusNameSet	  = minusUniqSet
elemNameSet       = elementOfUniqSet
nameSetToList     = uniqSetToList
delFromNameSet    = delOneFromUniqSet
foldNameSet	  = foldUniqSet
filterNameSet	  = filterUniqSet
intersectNameSet  = intersectUniqSets

delListFromNameSet set ns = foldl delFromNameSet set ns

intersectsNameSet s1 s2 = not (isEmptyNameSet (s1 `intersectNameSet` s2))
\end{code}


%************************************************************************
%*									*
\subsection{Free variables}
%*									*
%************************************************************************

These synonyms are useful when we are thinking of free variables

\begin{code}
type FreeVars	= NameSet

plusFV   :: FreeVars -> FreeVars -> FreeVars
addOneFV :: FreeVars -> Name -> FreeVars
unitFV   :: Name -> FreeVars
emptyFVs :: FreeVars
plusFVs  :: [FreeVars] -> FreeVars
mkFVs	 :: [Name] -> FreeVars
delFV    :: Name -> FreeVars -> FreeVars
delFVs   :: [Name] -> FreeVars -> FreeVars

isEmptyFVs  = isEmptyNameSet
emptyFVs    = emptyNameSet
plusFVs     = unionManyNameSets
plusFV      = unionNameSets
mkFVs	    = mkNameSet
addOneFV    = addOneToNameSet
unitFV      = unitNameSet
delFV n s   = delFromNameSet s n
delFVs ns s = delListFromNameSet s ns
\end{code}


%************************************************************************
%*									*
		Defs and uses
%*									*
%************************************************************************

\begin{code}
type Defs = NameSet
type Uses = NameSet

type DefUse  = (Maybe Defs, Uses)
type DefUses = [DefUse]
	-- In dependency order: earlier Defs scope over later Uses
	-- For items (Just ds, us), the use of any member 
	-- of the ds implies that all the us are used too
	--
	-- Also, us may mention ds
	--
	-- Nothing => Nothing defined in this group, but
	-- 	      nevertheless all the uses are essential.
	--	      Used for instance declarations, for example

emptyDUs :: DefUses
emptyDUs = []

usesOnly :: Uses -> DefUses
usesOnly uses = [(Nothing, uses)]

mkDUs :: [(Defs,Uses)] -> DefUses
mkDUs pairs = [(Just defs, uses) | (defs,uses) <- pairs]

plusDU :: DefUses -> DefUses -> DefUses
plusDU = (++)

allUses :: DefUses -> Uses -> Uses
-- Collect all uses, removing defs
allUses dus uses
  = foldr get emptyNameSet dus
  where
    get (Nothing,   rhs_uses) uses = rhs_uses `unionNameSets` uses
    get (Just defs, rhs_uses) uses = (rhs_uses `unionNameSets` uses)
				     `minusNameSet` defs

findUses :: DefUses -> Uses -> Uses
-- Given some DefUses and some Uses, 
-- find all the uses, transitively. 
-- The result is a superset of the input uses;
-- and includes things defined in the input DefUses
-- (if they are used, of course)
findUses dus uses 
  = foldr get uses dus
  where
    get (Nothing, rhs_uses) uses
	= rhs_uses `unionNameSets` uses
    get (Just defs, rhs_uses) uses
	| defs `intersectsNameSet` uses
	= rhs_uses `unionNameSets` uses
	| otherwise	-- No def is used
	= uses

duDefs :: DefUses -> Defs
duDefs dus = foldr get emptyNameSet dus
  where
    get (Nothing, u1) d2 = d2
    get (Just d1, u1) d2 = d1 `unionNameSets` d2

duUses :: DefUses -> Uses
-- Defs are not eliminated
duUses dus = foldr get emptyNameSet dus
  where
    get (d1, u1) u2 = u1 `unionNameSets` u2
\end{code}