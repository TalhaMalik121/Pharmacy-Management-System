#include<iostream>
#include<string>
#include<fstream>

using namespace std;
struct pharmacy{
	int choice;
	int order_number;
	string customer_name;
	string date;
	int number_of_medicine;
	int drug_id[10];
	int medicine_no[10];
	int amount_of_medicine[10];
	int total_amount=0;
	
	string medicineName[10]={"Penadol","Multi Vitamins","Calcium CaC 1000","Arinac","Surbex Z","Flagell",
	"Rigix 10mg","Bruffen","Piriton","Hydroline Syrup"};
	double Medicine[10] = {2.00,4.00,13.00,8.00,5.00,3.00,1.00,12.00,6.00,120.00};
	
}*p=new pharmacy();
pharmacy orders[10];
int currentIndex=0;
void save_data_to_file()
{
	ofstream myfile;
	
	myfile.open("pharmacy.txt" ,ios::app);
	{
	for(int j=0;j<10;j++)
	{
	pharmacy *p =&orders[j];
	if(p->order_number!=0)
	{
	
	myfile<<p->order_number<<',';
	cin.ignore();
	myfile<<p->customer_name<<',';
	myfile<<p->date<<',';
	myfile<<p->number_of_medicine<<',';
                for(int i=0;i<p->number_of_medicine;i++)
                {
                myfile<<p->drug_id[i]<<',';
                myfile<<p->medicineName[(p->drug_id[i])-1]<<',';
                myfile<<p->medicine_no[i]<<',';
                myfile<<p->amount_of_medicine[i]<<',';
                }
                myfile<<p->total_amount;
                myfile<<endl;}
	}
	}
                myfile.close();
}


void load_data_from_file() {
    ifstream infile;
    infile.open("pharmacy.txt", ios::in);

    if (infile.is_open()) {
        for (int j = 0; j < 10; j++) {
            pharmacy *p = &orders[j];
            infile >> p->order_number;
            infile.ignore();  
            getline(infile, p->customer_name, ',');
            infile.ignore();  
            getline(infile, p->date, ',');
            infile >> p->number_of_medicine;
            infile.ignore(); 
            for (int i = 0; i < p->number_of_medicine; i++) {
                infile >> p->drug_id[i];
                infile.ignore(); 
                getline(infile, p->medicineName[p->drug_id[i] - 1], ',');
                infile >> p->medicine_no[i];
                infile.ignore();  
                infile >> p->amount_of_medicine[i];
                infile.ignore(); 
            }
            infile >> p->total_amount;
            infile.ignore();  
        }
        infile.close();
    } else {
        cout << "Unable to open the file" << endl;
    }
}

void take_order(){
	        pharmacy *p =&orders[currentIndex];
                  
				cout <<"\nAdd Order Details\n";
				cout <<"_____________________________________\n\n";
				cout <<"**************************************************************************\n";
				cout<<"DRUGS ID"<<"\tDRUGS TYPE"<<"   \t\tDRUGS NAME"<<"           DRUGS PRICE(Rs)"<<endl;
				cout <<"**************************************************************************\n";
                cout<<"0001"<<"\t"<<"\tOTC"<<"\t\t"<<"    Penadol"<<"		        Rs 2.00"<<endl;
                cout<<"0002"<<"\t"<<"\tOTC"<<"\t\t"<<"    Multi Vitamins"<<"		Rs 4.00"<<endl;
                cout<<"0003"<<"\t"<<"\tOTC"<<"\t\t"<<"    Calcium CaC 1000"<<"		Rs 13.00"<<endl;
                cout<<"0004"<<"\t"<<"\tOTC"<<"\t\t"<<"    Arinac"<<"		        Rs 8.00"<<endl;
                cout<<"0005"<<"\t"<<"\tOTC"<<"\t\t"<<"    Surbex Z"<<"	 	        Rs 5.00"<<endl;
                cout<<"0006"<<"\t"<<"\tOTC"<<"\t\t"<<"    Flagell"<<" 		        Rs 3.00"<<endl;
                cout<<"0007"<<"\t"<<"\tOTC"<<"\t\t"<<"    Rigix 10mg"<<"		        Rs 1.00"<<endl;
                cout<<"0008"<<"\t"<<"\tOTC"<<"\t\t"<<"    Bruffen"<<"	      		Rs 12.00"<<endl;//1353fn
                cout<<"0009"<<"\t"<<"\tOTC"<<"\t\t"<<"    Piriton"<<"	     		Rs 6.00"<<endl;
                cout<<"0010"<<"\t"<<"\tOTC"<<"\t\t"<<"    Hydroline Syrup"<<"		Rs 120.00"<<endl;
                cout<<" "<<endl;
                cout<<"Type Order Number: ";
                cin>>p->order_number;
                cin.ignore();
                cout<<"Enter Customer Name: ";
                getline(cin,p->customer_name);
                cout<<"Enter Date: ";
                getline(cin,p->date);
                cout<<"How Many Medicine You Want to Order: \n(Maximum is 10 Order for each transation)\n";
                cin>>p->number_of_medicine;
                if ((p->number_of_medicine)>10)
				{
					cout << "The Medicine you order is exceed the maximum amount of order !";
					system("pause");
				}
				else{
				
                for(int i=0;i<p->number_of_medicine;i++)
                {
                cout<<"Please Enter Your Selection: "<<endl;
                cin>>p->drug_id[i];
                cout<<p->medicineName[(p->drug_id[i])-1]<<endl;
                cout<<"How medicine do you want: ";
                cin>>p->medicine_no[i];
                
                p->amount_of_medicine[i]=p->medicine_no[i]*p->Medicine[(p->drug_id[i])-1];
                
                cout<<"Amount You Need To Pay is: "<<"Rs "<<p->amount_of_medicine[i]<<endl<<endl;
                
                p->total_amount=p->total_amount+p->amount_of_medicine[i];
                }
                cout<<"Total Amount You have To pay: "<<"Rs "<<p->total_amount<<endl;
                currentIndex++;
                
cout<<"==========================================================================="<<endl;
cout << "Order Taken Successfully"<<endl;
cout<<"==========================================================================="<<endl;
cout << "Go to Reciept Menu to Pay The Bill"<<endl;
cout<<"==========================================================================="<<endl;
}}

void delete_order(){
	int OrderToDelete;
	cout<<"Enter Order Number To Delete: ";
	cin>>OrderToDelete;
	pharmacy *p =&orders[OrderToDelete-1];
for(int i =0;i<10;i++)	{
	if(OrderToDelete==orders[i].order_number)
	{ 
		for (int j = i; j<currentIndex; j++) 		
			{
                orders[j] = orders[j + 1]; 
            }
            currentIndex--;
	cout<<"Order Deleted Successfully\n";
	return;
	}}
    cout<<"Can not delete from an empty list.\n";	
}

void modify_order(){
	int OrderToModify;
	cout<<"Enter Order To MOdify: ";
	cin>>OrderToModify;
	pharmacy *p =&orders[OrderToModify-1];
	for(int i =0;i<10;i++)	
	{
	if(OrderToModify==orders[i].order_number)
	{
        cin.ignore();
        cout<<"Enter Customer Name: ";
        getline(cin,p->customer_name);
        cout<<"Enter Date: ";
        getline(cin,p->date);
        cout<<"How Many Medicine You Want to Order: \n(Maximum is 10 Order for each transation)\n";
        cin>>p->number_of_medicine;
        if ((p->number_of_medicine)>10)
		{
			cout << "The Medicine you order is exceed the maximum amount of order !";
			system("pause");
		}
		else{		
         for(int i=0;i<p->number_of_medicine;i++)
                {
                cout<<"Please Enter Your Selection: "<<endl;
                cin>>p->drug_id[i];
                cout<<p->medicineName[(p->drug_id[i])-1]<<endl;
                cout<<"How medicine do you want: ";
                cin>>p->medicine_no[i];
                p->amount_of_medicine[i]=p->medicine_no[i]*p->Medicine[(p->drug_id[i])-1];
                cout<<"Amount You Need To Pay is: "<<"Rs "<<p->amount_of_medicine[i]<<endl<<endl;
                p->total_amount=0;
                p->total_amount=p->total_amount+p->amount_of_medicine[i];
                }
                cout<<"Total Amount You have To pay: "<<"Rs "<<p->total_amount<<endl;
                currentIndex++;
cout<<"==========================================================================="<<endl;
cout << "Order Modified Successfully"<<endl;
cout<<"==========================================================================="<<endl;
cout << "Go to Reciept Menu to Pay The Bill"<<endl;
cout<<"==========================================================================="<<endl;
}}
}}
	
void receipt_payment(){
	int n=0;
	int Receipt_no;
	cout<<"Enter Receipt Number: ";
	cin>>Receipt_no;
	cout<<endl;
	pharmacy *p =&orders[Receipt_no-1];
	for(int i=0;i<10;i++)
   {
	if(Receipt_no==orders[i].order_number)
	{
		n=1;
	cout<<"=================================================================="<<endl;
	cout<<"******************Receipt And Payment*************************"<<endl;
	cout<<"=================================================================="<<endl<<endl;
		cout<<"\t\t|| Order_Number:          "<<p->order_number<<endl;
        cout<<"\t\t|| Customer Name:         "<<p->customer_name<<endl;
        cout<<"\t\t|| Date:                  "<<p->date<<endl;
        cout<<"\t\t|| Number Of Medicine:    "<<p->number_of_medicine<<endl;
        for(int i=0;i<p->number_of_medicine;i++)
        {
            cout<<"\t\t|| Drug ID:               "<<p->drug_id[i]<<endl;
            cout<<"\t\t|| Medicine Name:         "<<p->medicineName[p->drug_id[i]-1]<<endl;
        
        cout<<"\t\t|| Medicine NO:           "<<p->medicine_no[i]<<endl;
        cout<<"\t\t|| Amount Of Medicine: "<<"Rs "<<p->amount_of_medicine[i]<<endl;
		}
        cout<<"\t\t|| Total Amount You have To pay: "<<"Rs "<<p->total_amount<<endl;
        int Payment;
		cout<<"\nHow Much Money You Would Like To Pay: ";
        cin>>Payment;
        int x=p->total_amount-Payment;
        cout<<endl;
        cout<<"--------------------------------------------------------------"<<endl;
        cout<<"Paid "<<"Rs: "<<Payment<<endl;
        if(x>0)
        {
        cout<<"Payment Left: "<<x<<endl; 
        }
		if(x<0) 
		{
				x=x*-1;
			cout<<"Return Rupees: "<<x<<endl;   
		}		
}}
if(n==0)
{
	cout<<"Receipt Not Found"<<endl;
}}

void daily_summary() {
		cout<<"==============================================================================="<<endl;
	cout<<"**************************Daily Summary********************************"<<endl;
	cout<<"==============================================================================="<<endl<<endl;
    cout << "===============================================================================" << endl;
    cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
    cout << "=======++==================++================++===============++===============" << endl;
    for (int j = 0; j < 10; j++) 
	{
        pharmacy *p = &orders[j];
        if (p->order_number != 0) 
		{
            for (int i = 0; i < p->number_of_medicine; i++)
			{
            cout << "OTC"<< "\t\t\t" << p->medicineName[p->drug_id[i] - 1] << "\t\t\t" << p->medicine_no[i] << "\t\t\t" << p->amount_of_medicine[i] << endl<<endl;
			}	   
        }
    }
}

void exit_program(){
	cout<<"===================================================================================\n";
	cout<<"\n\t\t\tWe are exiting the program\n"<<endl;
	cout<<"===================================================================================\n";
	cout<<"\t\t\t\tThank You!"<<endl;
	
}
main(){
	while(true)
	{
	system("COLOR 6");
		system("cls");
		cout<<"\t\t\t    Pharmacy Management System \n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout<<"\t\t||\t2. Delete latest Medicine order\t\t ||\n";
		cout<<"\t\t||\t3. Modify Order List \t\t\t ||\n";
		cout<<"\t\t||\t4. Print the Reciept and Make Payment \t ||\n";
		cout<<"\t\t||\t5. Daily Summary of total Sale \t\t ||\n";
		cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t||\t7. Save Data To File\t\t\t ||\n";
		cout<<"\t\t||\t8. Load Data From File\t\t\t ||\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Enter choice: ";
		cin>>p->choice;
		switch (p->choice)
		{       
			case 1:
			{   system("cls");
				take_order();
				system("PAUSE");
				break;
			}
			
			case 2:
				{system("cls");
					delete_order();
					system("PAUSE");
					break;
					
				}
			case 3:
				{system("cls");
					modify_order();
					system("PAUSE");
					break;
				}
				
			case 4:
				{system("cls");
					receipt_payment();
					system("PAUSE");
					break;
				}
				
			case 5:
				{system("cls");
					daily_summary();
					system("PAUSE");
					break;
				}
			case 6:
				{	system("cls");
					exit_program();
					save_data_to_file();
					system("PAUSE");
					exit(0);
					break;
				}
					case 7:
				{	system("cls");
					save_data_to_file();
					system("PAUSE");
					break;
				}
					case 8:
				{	system("cls");
					load_data_from_file();
					system("PAUSE");
					break;
				}
			default:
				{	system("cls");
					cout<<"Invalid Input";
					system("PAUSE");
					break;	
				}
				}
		}
		}