#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//user input ( void reference function )
void inputParticipant ( string name[999], string phoneNumber[999], string emergencyNumber[999], string email[999], int &arraySize ) 
{
	cout<<"\nEnter your name : ";
	cin.ignore();
	getline ( cin , name[arraySize] );
	
	cout<<"\nEnter your phone number : ";
	getline ( cin , phoneNumber[arraySize] );
	
	cout<<"\nEnter an emergency number : ";
	getline ( cin , emergencyNumber[arraySize] );
	
	cout<<"\nEnter your email : ";
	getline ( cin , email[arraySize] );
}

//display ( void function without parameter )
void displayRaceInfo ()
{
	cout<<"\n"<<setw(81)<<setfill('=')<<"\n";
	cout<<"DISTANCE\t\tNATIONALITY\t\tCATEGORY\t\tFEE(RM)\n";
	cout<<setw(81)<<setfill('=')<<"\n";
	cout<<"3KM\t\t\tMALAYSIAN\t\tADULT\t\t\tRM 25.00\n"; 
	cout<<"						KIDS\t\t\tRM 10.00\n";
	cout<<"						SENIOR\t\t\tRM 15.00\n"<<endl;
	cout<<"			NON-MALAYSIAN\t\tADULT\t\t\tRM 30.00\n";
	cout<<"						KIDS\t\t\tRM 15.00\n";
	cout<<"						SENIOR\t\t\tRM 20.00\n"<<endl;
	cout<<setw(81)<<setfill('-')<<"\n";
	cout<<"6KM\t\t\tMALAYSIAN\t\tADULT\t\t\tRM 35.00\n";
	cout<<"						SENIOR\t\t\tRM 25.00\n"<<endl;
	cout<<"			NON-MALAYSIAN\t\tADULT\t\t\tRM 40.00\n";
	cout<<"						SENIOR\t\t\tRM 30.00\n";
	cout<<setw(81)<<setfill('=')<<"\n";	
}

void displayAdditionalItem ()
{
	cout<<"\nWe got some additional item for participating this marathon"<<endl;
	cout<<setw(76)<<setfill('=')<<"\n";
	cout<<"CODE COMBO\tITEMS\t\t\t\t\t\tPRICE(RM)\n";
	cout<<setw(76)<<setfill('=')<<"\n";
	cout<<"C1\t\tMedal + T-shirt + Cap + Limited Water Bottle\tRM 50.00\n";
	cout<<"C2\t\tBag + T-shirt + Cap\t\t\t\tRM 30.00\n";
	cout<<"C3\t\tBag + T-shirt\t\t\t\t\tRM 20.00\n";
	cout<<"C4\t\tT-shirt\t\t\t\t\t\tRM 15.00\n";
	cout<<setw(76)<<setfill('=')<<"\n"<<endl;
}

void displayShippingInfo ()
{
	cout<<"\n"<<setw(50)<<setfill('=')<<"\n";
	cout<<"CODE\t\tDELIVERY\t\tPRICE(RM)\n";
	cout<<setw(50)<<setfill('=')<<"\n";
	cout<<"PM\t\tPENINSULAR MALAYSIA\tRM 5\n";
	cout<<"SS\t\tSABAH & SARAWAK\t\tRM 7\n";
	cout<<"OS\t\tOVERSEAS\t\tRM 40\n";
	cout<<setw(50)<<setfill('=')<<"\n";
}

void displayRefreshmentKit ()
{
	cout<<"\nWe also provide some refreshment kit"<<endl;
	cout<<setw(99)<<setfill('=')<<"\n";
	cout<<"CODE COMBO\tITEMS\t\t\t\t\t\t\t\t\tPRICE(RM)\n";
	cout<<setw(99)<<setfill('=')<<"\n";
	cout<<"CA\t\tCombo A ( ROTI GARDENIA + ENERGYBYTE BAR + MINERAL WATER (500ml) )\tRM 4.00\n";
	cout<<"CB\t\tCombo B ( ROTI GARDENIA + 100PLUS WATER (500ml) )\t\t\tRM 4.00\n";
	cout<<"CC\t\tCombo C ( ROTI GARDENIA + MINERAL WATER (500ml) )\t\t\tRM 2.50\n";
	cout<<setw(99)<<setfill('=')<<"\n";	
}

void displayPaymentMethod ()
{
	cout<<"\n"<<setw(35)<<setfill('=')<<"\n";
	cout<<"PAYMENT CODE\t\tDISCOUNT\n";
	cout<<setw(35)<<setfill('=')<<"\n";
	cout<<"1 [ ONLINE BANKING ]\t\t0%\n";
	cout<<"2 [ SHOPEE PAY ]\t\t5%\n";
	cout<<setw(35)<<setfill('=')<<"\n";
}

double calcTicketPrice ( char ticketType[999], char citizenship, int &a, int &s, int &k, int &arraySize )
{
	int distance;
	double ticketP[999];
	char registerT;
	
	if ( citizenship == 'M' || citizenship == 'm')
		{
			cout<<"\nEnter your distance ( KM ) : ";
			cin>>distance;
			
			//nested selection for ticket
			if ( distance == 3 )
				{
					cout<<"\nDo you want to register as < ADULT [ A ] / KID [ K ] / SENIOR [ S ] > ? : ";
					cin>>registerT;
					if ( registerT == 'A' || registerT == 'a' )
						{
							ticketP[arraySize] = 25;
							ticketType[arraySize] = 'A';
							a++;
						}
					else if ( registerT == 'K' || registerT == 'k' )
						{
							ticketP[arraySize] = 10;
							ticketType[arraySize] = 'K';
							k++;
						}
					else if ( registerT == 'S' || registerT == 's' )
						{
							ticketP[arraySize] = 15;
							ticketType[arraySize] = 'S';
							s++;
						}
					else 
						{
							cout<<"\nInvalid code";
							return 0;
						}		
				}	
			else if ( distance == 6 )
				{
					cout<<"\nDo you want to register as < ADULT [ A ] / SENIOR [ S ] > ? : ";
					cin>>registerT;
					if ( registerT == 'A' || registerT == 'a' )
						{
							ticketP[arraySize] = 35;
							ticketType[arraySize] = 'A';
							a++;
						}						
					else if ( registerT == 'S' || registerT == 's' )
						{
							ticketP[arraySize] = 25;
							ticketType[arraySize] = 'S';
							s++;
						} 
					else 
						{
							cout<<"\nInvalid code";
							return 0;
						}
				}
			else 
				{
						cout<<"\nInvalid code";
						return 0;
				}
		}
			
	else if( citizenship == 'N' || citizenship == 'n')
		{
			cout<<"\nEnter your distance ( KM ) : ";
			cin>>distance;			
			if ( distance == 3 )
				{
					cout<<"\nDo you want to register as < ADULT [ A ] / KID [ K ] / SENIOR [ S ] > ? : ";
					cin>>registerT;					
					if ( registerT == 'A' || registerT == 'a' )
						{
							ticketP[arraySize] = 30;
							ticketType[arraySize] = 'A';
							a++;
						}						
					else if ( registerT == 'K' || registerT == 'k' )
						{
							ticketP[arraySize] = 15;
							ticketType[arraySize] = 'K';
							k++;
						}						
					else if ( registerT == 'S' || registerT == 's' )
						{
							ticketP[arraySize] = 20;
							ticketType[arraySize] = 'S';
							s++;
						}
					else 
						{
							cout<<"\nInvalid code";
							return 0;
						}							
				}	
			else if ( distance == 6 )
				{
					cout<<"\nDo you want to register as < ADULT [ A ] / SENIOR [ S ] > ? : ";
					cin>>registerT;					
					if ( registerT == 'A' || registerT == 'a' )
						{
							ticketP[arraySize] = 40;
							ticketType[arraySize] = 'A';
							a++;
						}						
					else if ( registerT == 'S' || registerT == 's' )
						{
							ticketP[arraySize] = 30;
							ticketType[arraySize] = 'S';
							s++;
						} 
					else 
						{
							cout<<"\nInvalid code";
							return 0;
						}
				}
			else
				{
					cout<<"\nInvalid code";
					return 0;	
		
				}
		}
		return ticketP[arraySize];
	}
	


double calcAddItem ( char addItem, int &arraySize )
{
	double addItemprice[999];
	string addCode;
	
	if ( addItem == 'Y' || addItem == 'y' )
			{
				cout<<"\nEnter additional item code : ";
				cin>>addCode;
			
				if ( addCode == "C1" )
					addItemprice[arraySize] = 50;
					
				else if ( addCode == "C2" )
					addItemprice[arraySize] = 30;
					
				else if ( addCode == "C3" )
					addItemprice[arraySize] = 20;
					
				else if ( addCode == "C4" )
					addItemprice[arraySize] = 15;
			}
	else if ( addItem == 'N' || addItem == 'n' )
	{
		cout<<"Alright.\n";
		addItemprice[arraySize] = 0;
	}
	else
	{
		cout<<"Invalid code.\n";
		addItemprice[arraySize] = 0;
	}	
	return addItemprice[arraySize];
}

double calcRefreshmentKit ( string kit )
{
	double kitPrice;
	
	if ( kit == "CA" || kit == "ca" )
	 	kitPrice = 4.00;
	 		
	else if ( kit == "CB" || kit == "cb" )
		kitPrice = 4.00;	
			
	else if ( kit == "CC" || kit == "cc" )
		kitPrice = 2.50;
		
	else if ( kit == "N")
		kitPrice = 0;
		
	return kitPrice;
}

double shipping ( string shipCode )
{
	double shipPrice;
				
	if ( shipCode == "PM" )
		shipPrice = 5;
						
	else if ( shipCode == "SS" )
		shipPrice = 7;
					
	else if ( shipCode == "OS" )
		shipPrice = 40;
						
	else 
		cout<<"Invalid code";
		
	return shipPrice;
}
	
double calcPayment ( int payment, int &arraySize )
{
	double discount[999];
	
	switch ( payment )
	{
		case 1 :
			discount[arraySize] = 0;
			break;
				
		case 2 : 
			discount[arraySize] = 0.05;
			break;
			
		default:
			cout<<"Invalid code";
	}
	return discount[arraySize];
}

double calcTotal (double total[999], double ticketP[999], double addItemprice[999], double discount[999], double shipPrice[999], double kitPrice[999], int &arraySize )
{	
	discount[arraySize] = ( ticketP[arraySize] + addItemprice[arraySize] + shipPrice[arraySize] + kitPrice[arraySize] ) * discount[arraySize];
	total[arraySize] = ( ticketP[arraySize] + addItemprice[arraySize] + shipPrice[arraySize] + kitPrice[arraySize] ) - discount[arraySize];
	
	return total[arraySize];
}

int main()
{
	//Initialization variables
	string name[999], email[999], phoneNumber[999], emergencyNumber[999], addCode, shipCode, kit;
	int maxA = 0, maxS = 0, maxK = 0, minA = 0, minS = 0, minK = 0, arraySize = 0, i, a = 0, s = 0, k = 0, distance, totalTicket= 0, payment ; 
	double total[999],ticketP[999], shipPrice[999], discount[999], addItemprice[999], kitPrice[999];
	char ticketType[999], citizenship, addItem, registerT, program;
	
	cout<<"\t\t\t"<<setw(78)<<setfill('=')<<"\n";
	cout<<"\t\t\t\t   WELCOME TO HARIMAUHUSTLE MARATHON RUN REGISTRATION SYSTEM\n";
	cout<<"\t\t\t"<<setw(78)<<setfill('=')<<"\n"<<endl;
	
	cout<<"Do you want to start this program < YES [Y] / NO [N] > ? : ";
	cin>>program;
	
	//while loop
	while ( program == 'Y' || program == 'y') {
	int a = 0, s = 0, k = 0;		
	inputParticipant ( name, phoneNumber, emergencyNumber, email , arraySize);
	
	displayRaceInfo ();
	
	cout<<"\nEnter your citizenship < Malaysian [M] | Non-Malaysian [N] > : ";
	cin>>citizenship;
	
	// Ticket Price
	ticketP[arraySize] = calcTicketPrice ( ticketType, citizenship, a, s, k, arraySize );
	
	// function return value without parameter
	displayAdditionalItem ();
	
	// Additional Item
	cout<<"Do you want to add an additional item < YES [Y] / NO [N] > ? :";
	cin>>addItem;
	addItemprice[arraySize] = calcAddItem ( addItem, arraySize );	
	
	// Refreshment Kit
	displayRefreshmentKit ();
	cout<<"\nDo you want to get the refreshment kit < ENTER ITEM CODE / NO [N] > ? : ";
	cin>>kit;
	kitPrice[arraySize] = calcRefreshmentKit ( kit );
	
	// Shipping
	displayShippingInfo ();
	cout<<"\nEnter your shipping code : ";
	cin>>shipCode;
	shipPrice[arraySize] = shipping ( shipCode );
		
	// Payment Method
	displayPaymentMethod ();	
	cout<<"\nPlease choose your payment method : ";
	cin>>payment;
	cout<<endl;
	discount[arraySize] = calcPayment( payment, arraySize );
	
	// Calculate Total
	total[arraySize] = calcTotal ( total, ticketP, addItemprice, discount, shipPrice, kitPrice, arraySize );
	
	// Min Max
	if ( a > s && a > k)
		maxA += a;
	else
		minA += a;
		
	if ( s > a && s > k)
		maxS += s;
	else
		minS += s;
		
	if ( k > s && k > a)
		maxK += k;
	else
		minK += k;
			
	totalTicket = totalTicket + (a + s + k);
	
	cout<<"\t\t\t\t"<<setw(30)<<setfill('=')<<"\n";
	cout<<"\t\t\t\t\t   RECEIPT\n";
	cout<<"\t\t\t\t"<<setw(30)<<setfill('=')<<"\n"<<endl;
	
	cout<<"\nTotal Ticket Sold : "<<totalTicket<<endl;
	
	arraySize++;
	cout<<fixed<<setprecision(2);
	cout<<setw(90)<<setfill('=')<<"\n";
	cout<<"CUSTOMER NAME\t\t|TICKET TYPE\t\t|DISCOUNT\t\t|TOTAL\n";
	cout<<setw(90)<<setfill('=')<<"\n";
	
	for ( i = 0; i < arraySize; i++)
	{	
		cout<<name[i]<<"\t\t\t "<<ticketType[i]<<"\t\t\t "<<"RM"<<discount[i]<<"\t\t\t RM"<<total[i]<<endl;
	}
	
	cout<<"Your certificate will be send to your email, thank you !\n";
	
	// Loop next customer
	cout<<"\nDo you want to register again as a next runner < YES [Y] / NO [N] > ? : ";
	cin>>program;
	
	}
	if ( maxA > maxS && maxA > maxK )
		cout<<"\nHighest Ticket Sold is Adult ticket with "<<maxA<<" ticket."<<endl;
	else if ( maxK > maxS && maxK > maxA )
		cout<<"\nHighest Ticket Sold is Kids ticket with "<<maxK<<" ticket."<<endl;
	else if ( maxS > maxA && maxS > maxK )
		cout<<"\nHighest Ticket Sold is Senior ticket with "<<maxS<<" ticket."<<endl;
		
	if ( minA < minS && minA < minK )
		cout<<"\nLowest Ticket Sold is Adult ticket with "<<maxA<<" ticket."<<endl;
	else if ( minK < minS && minK < minA )
		cout<<"\nLowest Ticket Sold is Kids ticket with "<<maxK<<" ticket."<<endl;
	else if ( minS < minA && minS < minK )
		cout<<"\nLowest Ticket Sold is Senior ticket with "<<maxS<<" ticket."<<endl;			
	
	cout<<setw(90)<<setfill('=')<<"\n";
	cout<<"CUSTOMER NAME\t\t|NO.PHONE\t\t|EMERGENCY NUMBER\t\t|EMAIL\n";
	cout<<setw(90)<<setfill('=')<<"\n";
		
	for ( i = 0; i < arraySize; i++)
	{
		cout<<name[i]<<"\t\t\t "<<phoneNumber[i]<<"\t\t\t "<<emergencyNumber[i]<<"\t\t\t\t "<<email[i]<<endl;
		cout<<"Your Order:\t\t|TICKET TYPE\t\t|DISCOUNT\t\t\t|TOTAL\n";
		cout<<"\t\t\t "<<ticketType[i]<<"\t\t\t "<<"RM"<<discount[i]<<"\t\t\t\t RM"<<total[i]<<"\n"<<endl;
	}	
	
	
	
	cout<<setw(90)<<setfill('=')<<"\n";
	cout<<endl;
	
	return 0;
}
