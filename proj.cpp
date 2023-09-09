#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;
#define MA 200
#define colorinv SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12)  //invalid input
#define colordfp SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11)   //cefault player
#define colordfc SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6)   //default cpu
#define coloruns SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4)   //underscore
#define colorwga SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13)  //wrong answer
#define colorfns SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10)  //finish jadval
#define colorfnsa SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9) //writed answer for help
struct jad 
{
	struct qstruct 
	{
		string Q,A; //Q question     A answer
		int I,N; // I shomare avalin khane soal        // N tedad khane kali soal
	};
	char khone[20][20];
	qstruct qamod[20][20],qofogh[20][20];
	int namod[20],nofogh[20]; //tedad soal haye har satr va soton
	int khaliavalie; //tedad khanehaye * nashode har jadval
	
}jadval[10];

void khatkesh(char a,char b,char c);
bool motmaen(string s,int j);
void chapjadval(jad mjad);
int farib(string s,int &d,int &a,int &b,jad &mjad);
void kochaker(string &s);
int convstoi(string s,int &j);
void makej(int kjad);
bool adde(char x);
void begir(string &s);
void solve(jad mjad);
	//score morede niad barahelp       //scori ke dar sorate komak kam mishavad    //scori ke be ezaye har khane dorost ezafe mishavad				
int needrate=10,ratedown=5,rateup=1;//tanzim nahve score dehi

int main()
{
	system( "Title Jadval Hassan_Ardeshir" );
	srand(time(0));
	string order;
	int tjad=0; //tedad jadval hayi ke ta alan sakhte shodeand!
	int k;
	while(1)
	{
		colordfc;
		cout<<"enter";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout<<" 'solve' ";
		colordfc;
		cout<<"to solve one of the available crossword puzzles or ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		cout<<"'make' ";
		colordfc;
		cout<<"to create a new one!\n";
		colordfp;
		//agar dastor digari vared konid payam invalid input namayesh dade mishavad!...
		while(1)
		{
			cin>>order;
			kochaker(order);
			colorinv;
			if(order!="solve" && order!="make")
				cout<<"invalid input!\n";
			else break;
			colordfp;
		}
		colordfc;
		if(order=="make") 
		{
			makej(tjad);
			tjad++;
		}
		if(order=="solve")
		{
			if(tjad>1) 
			{
				printf("choose from [1,%d]:\n",tjad);
				while(!(cin>>k) || k>tjad || k<1) //agar addad dade shode dar [1,tjad] nabashad in payam chap mishavad
				{ 
					colorinv;
					printf("invalid input, please choose from [1, %d]\n",tjad);
					colordfp;
				}
				solve(jadval[k-1]); //chon jadval ha az 0 shomare gozari shodeand
			}
			else 
				if(!tjad) //agar aslan jadvali make nashode bashad in payam dade mishavad
				{
					coloruns;
					cout<<"there is no crossword puzzle to solve!\n";
				}
				else solve(jadval[0]);
			
		}
	}
}

void kochaker(string &s) // tabdil horof bozorg be kochack englisi
{
	for(int i=0;i<s.length();i++)
		if(s[i]<='Z' && s[i]>='A')
			s[i]=s[i]-'A'+'a'; //agar s[i] bozorg bod kochak mikonad
}
bool adde(char x) // check mikonad ke ayaa character [0,9] ast ya kheir
{
	if(x>='0' && x<='9')
		return 1;
	return 0;
}
void begir(string &s) //khati ke karbar dar on chizi vared karde ra kamel vorodi migirad
{
	colordfp;
	do
	{
		getline(cin,s);
	}while(!s.length());
}
int farib(string s,int &d,int &a,int &b,jad &mjad) // dar code solve estefade mishavad
{
	int j=2;
	a=convstoi(s,j); //addad aval dar a rikhte mishavad 
	if(j==2 || j>=s.length()-3 || s[j]!='-' || s[j+2]!='-' || (s[j+1]!='h' && s[j+1]!='v')) // check mikonad ke a ra gerefte ast , edame s manand format khaste shode ast (-h-,-v-)
	{
		colorinv;
		cout<<"invalid input\n";
		return 0;
	}
	d=j+1;//khanei ke dar an h ya v neveshte shode ra zakhire mikonad
	j+=3; // j barabar shomare khane badi - dovom mishavad
	b=convstoi(s,j); // addad dovom dar b rikhte mishavad
	if(a<1 || a>15 || b<1 || (s[d]=='h' && b>mjad.namod[a-1]) || (s[d]=='v' && b>mjad.nofogh[a-1])) // sehat b , a check mishavad
	{
		colorinv;
		cout<<"invalid input\n";
		return 0;
	}
	return j; //agar hame chiz okay bood j barabar shomare khane bad az dovomin addad return mishavad 
}
void solve(jad mjad)
{
	int score=0,writed=0; // manzor az writed yani khanehayi ke karbar onha ra meghdar gozashte ast
	chapjadval(mjad);
	bool flagfinish=0;
	while(1)
	{
		if(writed==mjad.khaliavalie ||flagfinish)
		{
			colorfns;
			if(writed==mjad.khaliavalie) //agar flagfinish=1 bood niazi nist dastor zir ejra shavad
			{
				cout<<"the crossword puzzle solved successfully!\n"; 
			}
			cout<<"rate: "<<int((writed/mjad.khaliavalie)*100)<<"%\n"; 
			return;
		}
		string s;
		colordfp;
		begir(s);
		kochaker(s);
		int a,b,j,d,u;
		if(s[0]=='q' && s.length()>6 && s[1]==' ') //check mikonad ke aya fard question darad?
		{
		    u=farib(s,d,a,b,mjad); // in tabe s ra tahlil mikonad darvaghe agar dar format dade shode %d-h-%d || %d-v-%d bood 
								   // a ra barabar adad aval , b ra barabar addad dovom mikonad 
								   //,u ra barabar shomare avalin khane bad az addad dovom mikonad
								   //agar ham dar format dorosti nabod u ra barabar 0 mikonad 
			if(!u) continue; // payam invalid input dar sorat u=0 dar khode tabe farim chap mishavad
			if(!motmaen(s,u)) // in tabe check mikonad ke bad az addad dovom chize digari neveshte nashode bashad!
			{
				colorinv;
				cout<<"invalid input\n";
				continue;
			}	
			colordfc;
			if(s[d]=='v') 
			{
				cout<<mjad.qamod[a-1][b-1].Q<<'\n';
			}
			else
			{
				cout<<mjad.qofogh[a-1][b-1].Q<<'\n';
			}
			continue;
		}
		if(s[0]=='a' && s.length()>8 && s[1]==' ') // check mikonad ke aya fard answer darad?
		{
			u=farib(s,d,a,b,mjad);// manand question S ra tahlil mikonad va meghdar dehi ha ra anjam midahad
			if(!u) continue;
			u++;
			if(u>=s.length() || s[u-1]!=' ' || s[u]==' ') //check mishavad ke bad az addad dovom yek space zade shode va baad on chizi neveshte shode ast
			{   //agar chizi neveshte nabod in payam chap mishavad ya agar space zade nashode bod
				colorinv;
				cout<<"invalid input\n";
				continue;
			}
			string answer=s.substr(u,s.length()-1);// javab dade shode tavasot karbar dar answer rikhte mishavd
			a--;b--; //hafeze ma 0base mibashad
			bool flagansn=0;
			if(s[d]=='v')
			{
				if(answer!=mjad.qamod[a][b].A) //ba javab dade shode dar make check mishavad
				{
					colorwga;
					cout<<"wrong answer!\n";
					continue;
				}
				else
				{
					for(int i=0;i<answer.length();i++)
					{
						if(mjad.khone[i+mjad.qamod[a][b].I][a]==' ')//be andaze (tedad khanehaye khali ke por mishavand) *rateup be score ezafe mishavad;
						{
							score+=rateup;
							flagansn=1; 
							writed++; //tedad writed ha ziad mishavad dar if avarde shode ta tekrari nashmorad
						}
						mjad.khone[i+mjad.qamod[a][b].I][a]=answer[i];
					}
					if(!flagansn) 
					{
						colorfnsa;
						cout<<"you have completed this answer!\n";	
						continue;	
					}
				}
			}
			else
			{    
				if(answer!=mjad.qofogh[a][b].A)
				{
					colorwga;
					cout<<"wrong answer!\n";
					continue;
				}
				else
				{
					for(int i=0;i<answer.length();i++)
					{
						if(mjad.khone[a][i+mjad.qofogh[a][b].I]==' ')
						{
							score+=rateup;
							writed++;
							flagansn=1;
						}
						mjad.khone[a][i+mjad.qofogh[a][b].I]=answer[i];
					}
					if(!flagansn) 
					{
						colorfnsa;
						cout<<"you have completed this answer!\n";
						continue;	
					}
				}
			}
			chapjadval(mjad);
			continue;
		}
		if(s=="finish") //agar dastor finish bod dar ebtade while marhale bad barname solve payan miyabad
		{
			flagfinish=1;
		}
		else if(s[0]=='h') //check mikonad ke aya karbar help mikhahad
		{
			u=farib(s,d,a,b,mjad);// s ra tahlil mikonad , meghdardehi ha ra ham anjam midahad
			int f=0;
			int g[20];
			if(!u) continue;
			if(!motmaen(s,u)) //check mikonad ke bad az adad dovom harf nabashad
			{
				colorinv;
				cout<<"invalid input\n";
				continue;
			}	
			if(needrate>score) // bayad check shavad ke score be andaze need rate bashad
			{
				coloruns;
				printf("your score is under %d!\n",needrate);
				continue;
			}
			a--;b--; // 0base hastim
			if(s[d]=='v')
			{
				for(int i=mjad.qamod[a][b].I;i<mjad.qamod[a][b].I+mjad.qamod[a][b].N;i++)
					if(mjad.khone[i][a]==' ') //tedad khanehaye khali soal madnazar shemorde mishavad va mokhtasat onha zakhire mishavad
					{
						g[f]=i;
						f++;
					}
				if(!f) // agar khane khali nabod
				{
					colorfnsa;
					cout<<"you’ve completed this answer!\n";
					continue;
				}
				u=g[rand()%f];
				mjad.khone[u][a]=mjad.qamod[a][b].A[u-mjad.qamod[a][b].I]; // khane khali ra por mikonad
			}
			else
			{ 
				for(int i=mjad.qofogh[a][b].I;i<mjad.qofogh[a][b].I+mjad.qofogh[a][b].N;i++)
					if(mjad.khone[a][i]==' ')
					{
						g[f]=i;
						f++;
					}
				if(!f)
				{
					colorfnsa;
					cout<<"you’ve completed this answer!\n";
					continue;
				}
				u=g[rand()%f];
				mjad.khone[a][u]=mjad.qofogh[a][b].A[u-mjad.qofogh[a][b].I];
				
			}
			score-=ratedown; // score ra kam mikonad
			writed++;//tedad writed ha ra ziad mikonad
			chapjadval(mjad);
		}
		else {
				colorinv;
				cout<<"invalid input\n"; // agar hich kodam az dastor ha nabod!
			 }
	}
}
int convstoi(string s,int &j) //az khane j dar s shoro mikonad va shoro be tabdil addad mikonad agar digar natavanesh khoroji midahad
{
	int X=0;
	while(j<s.length() && adde(s[j]))
	{
		X*=10;
		X+=s[j]-'0'; // tabdil character be addad 
		j++; 
	}
	return X; // agar aslan addad natavanest besazad 0 khoroji midahad
}
bool motmaen(string s,int j) // check mikonad aya dar s[j,s.length()-1] harfi vojod darad (bejoz space)
{
	bool flag=1;
	for(int i=j;i<s.length();i++)
	{
		if(s[i]!=' ') {flag=0;break;}
	}
	return flag;
}
void makej(int kjad)
{
	colordfc;
	cout<<"which squares are black?\n";
	string s;
	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
			jadval[kjad].khone[i][j]=' ';
	int X,Y,j;
	int nblack=0;
	cin.ignore();
	while(1) //khone haye por ra vorodi migirad
	{
		j=0;
		colordfp;
		begir(s); 
		if(s=="***") break;
		X=convstoi(s,j); // adad aval vorodi gerefte mishavad , j ham barabar shomare khane bad az addad mishavad
		if(!j || j>=s.length()-1 || s[j]!='-') // check mishavad ke aya addad motabar bood va baad az adad - ast ya na
		{
			colorinv;
			cout<<"invalid input\n";
			continue;
		}
		j++; // j barabar shomare khane aval add dovom mishavad
		Y=convstoi(s,j); //addad dovom ra vorodi migirad va j ham barabar shomare khone bad az addad mishavad
		   //check mishavad  ke bad az addad dovom chize ezafe nabashad
		if(!motmaen(s,j) || X>15 || X<1 || Y>15 || Y<1)  // addad ra check mikonad ke dar [1,15] bashad
		{
			colorinv;
			cout<<"invalid input\n";
			continue;
		}
		jadval[kjad].khone[X-1][Y-1]='*';//on khane ra black mikonad
		nblack++;//tedad khane haye siah ezafe mishavad
	}
	jadval[kjad].khaliavalie=225-nblack; // tedad khane haye khali jadval mored nazar hesab mishavad
	int u;
	bool flag;
	for(int i=0;i<15;i++) // tedad soalhaye har radif , moshakhasat anha sabt mishavad
	{
		u=0;
		flag=0;
		for(int j=0;j<15;j++)
		{
			if(!flag && jadval[kjad].khone[i][j]!='*')
			{
				flag=1;
				u++; // tedad soal ha ziad mishavad albate hafeze 0base ast
				jadval[kjad].qofogh[i][u-1].I=j; // shomare khane aval soal morednazar sabt mishavad
				jadval[kjad].qofogh[i][u-1].N=0; // if(flag) payin in meghdar 1 mishavad!
			}
			if(jadval[kjad].khone[i][j]=='*')
				flag=0;
			
			if(flag)
			{
				jadval[kjad].qofogh[i][u-1].N++; //tedad khanehaye soal morednazar ziad mishavad
			}
		}
		jadval[kjad].nofogh[i]=u; //tedad soalha har radif sabt mishavad
	}
	for(int i=0;i<15;i++) // tedad soalhaye har soton , moshakhasat anha sabt mishavad
	{
		u=0;
		flag=0;
		for(int j=0;j<15;j++)
		{
			if(!flag && jadval[kjad].khone[j][i]!='*')
			{
				flag=1;
				u++;
				jadval[kjad].qamod[i][u-1].I=j;
				jadval[kjad].qamod[i][u-1].N=0;
			}
			if(flag && jadval[kjad].khone[j][i]=='*')
				flag=0;
			
			if(flag)
			{
				jadval[kjad].qamod[i][u-1].N++;
			}
		}
		jadval[kjad].namod[i]=u;
	}
	colordfc;
	cout<<"enter questions and answers.\n";
	
	for(int i=0;i<15;i++) // soal ha va javabhaye amodi  gerefte mishavad
	{
		for(int j=0;j<jadval[kjad].namod[i];j++)
		{
			colordfc;
			printf("%d-v-%d:\n",i+1,j+1);
			colordfp;
			begir(s); //soal ha gerefte mishavad
			kochaker(s);
			jadval[kjad].qamod[i][j].Q=s;
			begir(s); //javab gerefte mishavad
			while(s.length()!=jadval[kjad].qamod[i][j].N) // agar tedad horof s bishtar az fazaye khali soal bood chap mishavad
			{
				colorinv;
				cout<<"invalid input!\n";
				colordfp;
				begir(s);
			}
			kochaker(s);
			jadval[kjad].qamod[i][j].A=s;
		}
	}
	for(int i=0;i<15;i++) // soal ha va javabhaye ofoghi  gerefte mishavad 
	{
		for(int j=0;j<jadval[kjad].nofogh[i];j++)
		{
			colordfc;
			printf("%d-h-%d:\n",i+1,j+1);
			colordfp;
			begir(s);
			kochaker(s);
			jadval[kjad].qofogh[i][j].Q=s;
			begir(s);
			while(s.length()!=jadval[kjad].qofogh[i][j].N)
			{
				colorinv;
				cout<<"invalid input!\n";
				colordfp;
				begir(s);
			}
			kochaker(s);
			jadval[kjad].qofogh[i][j].A=s;
		}
	}
	colordfc;
	cout<<"the crossword puzzle made successfully!\n";	
}

void khatkesh(char a,char b,char c)
{
	char khath=205; //-
	for(int i=0;i<15;i++)
	{
		if(!i) //aval a chap mishavad
			cout<<a;
		else	
			cout<<b;
		cout<<khath<<khath<<khath; //---
	}
	cout<<c<<'\n';//c chap mishavad
}
void chapjadval(jad mjad) //jadval[kjad] ra chap mikonad
{
	//character haye morede niaz baraye khatkeshi jadval
	//baraye nam gozari az XY estefade shode ast yani ebtade soton va sepas radif gofte mishavad
		//+-        //-        //-+
	char leftup=201,midup=203,rightup=187;
	    //|         //+         //|
	char leftmid=204,midmid=206,rightmid=185;
        //+-          //-          //-+
	char leftdown=200,middown=202,rightdown=188;
	   //|
	char khatv=186;
	char por=178; // *
	
	for(int i=0;i<15;i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		if(!i)	//balatarin khate jadval chap mishavad
			khatkesh(leftup,midup,rightup);
		else 
			khatkesh(leftmid,midmid,rightmid);
		
		for(int j=0;j<15;j++)
		{
			cout<<khatv; // |
			
			if(mjad.khone[i][j]=='*') //age on khune por bashe por chap mikone
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout<<por<<por<<por;		
			}
			else 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout<<" "<<mjad.khone[i][j]<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		}
		cout<<khatv<<'\n'; //|
	}
	khatkesh(leftdown,middown,rightdown);//payintarin khat chap mishavad
}


