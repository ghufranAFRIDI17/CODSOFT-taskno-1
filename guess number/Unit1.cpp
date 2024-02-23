//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
int range_down;
int range_up;
int counter;
int hiden_number;

bool isvalid(const String str)
{
	for(int i=1;i<=str.Length();++i)
	{
		if(str[i]<'0' || str[i]>'9')
		{
			return false;
		}
	}
    return true;
}

int stringtoint(const String str)
{
	int number=0;
	for(int i=1;i<=str.Length();++i)
	{
		number*=10;
        number+=str[i]-'0';
	}
    return number;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	down_range->Enabled=true;
	up_range->Enabled=true;
	start->Enabled=true;
	restart->Enabled=false;
	input->Enabled=false;
	enter->Enabled=false;

	down_range->Text ="";
	up_range->Text="";
	turn->Text="";
	input->Text="";
	hiden->Text="";
	output->Text="Set Range";

	counter=0;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::startClick(TObject *Sender)
{
	String num1=down_range->Text;
	String num2=up_range->Text;
	if(num1=="" || !isvalid(num1))
	{
		down_range->Text="";
		if(num2=="" || !isvalid(num2))
		{
			up_range->Text="";
			output->Text="Set Valid +iv Integer Number as Range";
		}
		else
		{
			output->Text="Enter Valid +iv Integer Number as Starting Range";
		}
        return;
	}
	if(num2=="" || !isvalid(num2))
	{
		up_range->Text="";
		output->Text="Enter Valid +iv Integer Number as Ending Range";
		return;
	}
	range_down=stringtoint(num1);
	range_up=stringtoint(num2);
	if(range_down >= range_up)
	{
		down_range->Text="";
		up_range->Text="";
		output->Text="Starting Number should be less than Ending Number";
		return;
	}
	else if(range_down+1 >= range_up)
	{
    	down_range->Text="";
		up_range->Text="";
		output->Text="Minimum Range should be 3 (i.e 1-3)";
		return;
	}

	// valid range

	start->Enabled=false;
	down_range->Enabled=false;
	up_range->Enabled=false;
	restart->Enabled=true;
	enter->Enabled=true;
    input->Enabled=true;
	hiden->Text="*****";
	turn->Text=counter;
	output->Text="Guess the Hiden Number";

	// setting hiden_number

	int number1=rand()+2;
	int number2=rand()+7;
	int number3=rand()+3;
	int number4=number1*number2*number3;
	int difference=(range_up-range_down)+1;
	number4=number4%difference;
	hiden_number=number4+range_down;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::restartClick(TObject *Sender)
{
	down_range->Enabled=true;
	up_range->Enabled=true;
	start->Enabled=true;
	restart->Enabled=false;
	input->Enabled=false;
	enter->Enabled=false;

	down_range->Text ="";
	up_range->Text="";
	turn->Text="";
	input->Text="";
	hiden->Text="";
	output->Text="Set Range";

	counter=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::enterClick(TObject *Sender)
{
	String num=input->Text;
	if(num=="" || !isvalid(num))
	{
		input->Text="";
		output->Text="Enter Valid +iv Integer Number as Guess-Number";
		return;
	}
	int number = stringtoint(num);
	if(number<range_down || number> range_up)
	{
		input->Text="";
		output->Text="Guess the number Between Range";
		return;
	}
	if(number==hiden_number)
	{
		output->Text="Wow! Correct";
		hiden->Text=hiden_number;
		input->Enabled=false;
		enter->Enabled=false;
		return;
	}
	else if(number<hiden_number)
	{
		output->Text="Your Guess is Too Low";
		input->Text="";
		++counter;
		turn->Text=counter;
		return;
	}
	else
    {
		output->Text="Your Guess is Too High";
		input->Text="";
        ++counter;
		turn->Text=counter;
		return;
	}
}
//---------------------------------------------------------------------------
