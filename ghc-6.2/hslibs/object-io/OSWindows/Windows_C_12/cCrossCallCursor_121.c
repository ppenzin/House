/********************************************************************************************
	Clean OS Windows library module version 1.2.1.
	This module is part of the Clean Object I/O library, version 1.2.1,
	for the Windows platform.
********************************************************************************************/

/********************************************************************************************
	About this module:
	Routines related to cursor handling.
********************************************************************************************/
#include "cCrossCallCursor_121.h"


/*	Globals:
*/
static HCURSOR ghFatCrossCursor = NULL;
static HCURSOR ghHiddenCursor   = NULL;
static int gGlobalCursorCode    = -1;

/*	Cursor shape masks:
*/
static BYTE FatCrossCursorANDmask[128] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0x7f, 0xff,
	0xff, 0x80, 0x7f, 0xff, 0xff, 0x80, 0x7f, 0xff,

	0xff, 0x80, 0x7f, 0xff, 0xff, 0x80, 0x7f, 0xff,
	0xe0, 0x00, 0x03, 0xff, 0xe0, 0x3e, 0x01, 0xff,
	0xe0, 0x3e, 0x01, 0xff, 0xe0, 0x3e, 0x01, 0xff,
	0xe0, 0x3e, 0x01, 0xff, 0xe0, 0x3e, 0x01, 0xff,

	0xe0, 0x00, 0x01, 0xff, 0xf0, 0x00, 0x01, 0xff,
	0xff, 0x80, 0x7f, 0xff, 0xff, 0x80, 0x7f, 0xff,
	0xff, 0x80, 0x7f, 0xff, 0xff, 0x80, 0x7f, 0xff,
	0xff, 0x80, 0x7f, 0xff, 0xff, 0xc0, 0x7f, 0xff,

	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

static BYTE FatCrossCursorXORmask[128] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00,
	0x00, 0x3e, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00,

	0x00, 0x3e, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00,
	0x00, 0x3e, 0x00, 0x00, 0x0f, 0xff, 0xf8, 0x00,
	0x0f, 0xe3, 0xf8, 0x00, 0x0f, 0xe3, 0xf8, 0x00,
	0x0f, 0xe3, 0xf8, 0x00, 0x0f, 0xff, 0xf8, 0x00,

	0x00, 0x3e, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00,
	0x00, 0x3e, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00,
	0x00, 0x3e, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static BYTE HiddenCursorANDmask[128] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,

	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,

	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,

	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

static BYTE HiddenCursorXORmask[128] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static HCURSOR GetFatCrossCursor (void)
{
	if (ghFatCrossCursor != NULL)
		return ghFatCrossCursor;

	ghFatCrossCursor = CreateCursor (ghInst,
									 12, 13,	/* Hot spot */
									 32, 32,	/* width, heigth */
									 FatCrossCursorANDmask,
									 FatCrossCursorXORmask
		);

	return ghFatCrossCursor;
}	/* GetFatCrossCursor */

HCURSOR GetHiddenCursor (void)
{
	if (ghHiddenCursor != NULL)
		return ghHiddenCursor;

	ghHiddenCursor = CreateCursor (ghInst,
								   16, 16,		/* Hot spot */
								   32, 32,		/* width, heigth */
								   HiddenCursorANDmask,
								   HiddenCursorXORmask
		);

	return ghHiddenCursor;
}	/* GetHiddenCursor */

void DeleteCursors (void)
{
	if (ghFatCrossCursor != NULL)
	{
		DestroyCursor (ghFatCrossCursor);
		ghFatCrossCursor = NULL;
	}

	if (ghHiddenCursor != NULL)
	{
		DestroyCursor (ghHiddenCursor);
		ghHiddenCursor = NULL;
	}
}	/* GetHiddenCursor */

HCURSOR SetCursorFromCode (int code)
{
	switch (code)
	{
		case CURSARROW:
			return SetCursor (LoadCursor (0, IDC_ARROW));
		case CURSBUSY:
			return SetCursor (LoadCursor (0, IDC_WAIT));
		case CURSIBEAM:
			return SetCursor (LoadCursor (0, IDC_IBEAM));
		case CURSCROSS:
			return SetCursor (LoadCursor (0, IDC_CROSS));
		case CURSFATCROSS:
			return SetCursor (GetFatCrossCursor ());
		case CURSHIDDEN:
			return SetCursor (GetHiddenCursor ());
		default:
			return NULL;
	}
}	/* SetCursorFromCode */


int GetGlobalCursorCode (void)
{
	return gGlobalCursorCode;
}	/* GetGlobalCursorCode */

BOOL GlobalCursorSet (void)
{
	return gGlobalCursorCode != -1;
}	/* GlobalCursorSet */

/*	PA: this routine does not seem to be used anymore.
static void ClearGlobalCursorCode (void)
{
	gGlobalCursorCode = -1;
}
*/

static BOOL IsApplicationWindow (HWND hwnd)
{
	while (hwnd != NULL && hwnd != ghMainWindow)
		hwnd = GetWindow (hwnd, GW_OWNER);

	return (hwnd != NULL);
}

static HWND ApplicationWindowUnderCursor (void)
{
	POINT p;
	HWND hwnd;

	GetCursorPos (&p);
	hwnd = WindowFromPoint (p);

	if (IsApplicationWindow (hwnd))
		return hwnd;
	else
		return NULL;
}


/*	Cross call procedure implementations.
	Eval<nr> corresponds with a CrossCallEntry generated by NewCrossCallEntry (nr,Eval<nr>).
*/
void EvalCcRqSETGLOBALCURSOR (CrossCallInfo *pcci)	/* cursorcode; no result. */
{
	HWND hwnd;

	gGlobalCursorCode = pcci->p1;

	hwnd = ApplicationWindowUnderCursor ();

	if (hwnd != NULL)
		SetCursorFromCode (gGlobalCursorCode);

	MakeReturn0Cci (pcci);
}

void EvalCcRqRESETCURSOR (CrossCallInfo *pcci)		/* no params, no result. */
{
	HWND hwnd;

	gGlobalCursorCode = -1;

	hwnd = ApplicationWindowUnderCursor ();

	if (hwnd != NULL)
	{
		int hittestvalue;
		POINT p;

		GetCursorPos (&p);
		hittestvalue = SendMessage (hwnd, WM_NCHITTEST, 0, MAKELPARAM (p.x, p.y));
		SendMessage (hwnd, WM_SETCURSOR, (WPARAM) hwnd, MAKELPARAM (hittestvalue, WM_MOUSEMOVE));
	}
	MakeReturn0Cci (pcci);
}


/*	Install the cross call procedures in the gCrossCallProcedureTable of cCrossCall_121.
*/
void InstallCrossCallCursor ()
{
	CrossCallProcedureTable newTable;

	newTable = EmptyCrossCallProcedureTable ();
	AddCrossCallEntry (newTable, CcRqSETGLOBALCURSOR, EvalCcRqSETGLOBALCURSOR);
	AddCrossCallEntry (newTable, CcRqRESETCURSOR,     EvalCcRqRESETCURSOR);
	AddCrossCallEntries (gCrossCallProcedureTable, newTable);
}