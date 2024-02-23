//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *down_range;
	TLabel *rangeL;
	TEdit *up_range;
	TLabel *range_L;
	TButton *start;
	TButton *restart;
	TEdit *hiden;
	TEdit *input;
	TLabel *inputL;
	TEdit *output;
	TButton *enter;
	TEdit *turn;
	TLabel *turnL;
	void __fastcall startClick(TObject *Sender);
	void __fastcall restartClick(TObject *Sender);
	void __fastcall enterClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
