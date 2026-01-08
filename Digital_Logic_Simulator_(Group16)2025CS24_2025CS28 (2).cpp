#include <iostream>
#include <limits>
#include <windows.h>
using namespace std;

bool OR(bool a, bool b);
bool NOT(bool a);
bool AND(bool a, bool b);
bool XOR(bool a, bool b);
int checker(string number);
void headerOfTable();
void menu();
void header();
void visualHeader();
int handlePause();
void handleHalfAdder();
void setColor(int color);
void handleBasicGates();
void handleCombinatorialCircuit();
void handleFullAdder();
string numValidation(string userInput);
void handleCircuitMinimization();
void viewBooleanAlgebra();
void viewMinimizationMenu();
void MinimizationExample();
void MinimizationLawVerifier();
bool NAND(bool a, bool b);
bool NOR(bool a, bool b);

int main()
{
    int option;
    while (true)
    {
        setColor(11);
        header();
        setColor(12);
        menu();
        cin >> option;
        if (option == 1)
        {

            handleBasicGates();
        }

        else if (option == 2)
        {
            handleHalfAdder();
        }
        else if (option == 3)
        {
            handleFullAdder();
        }
        else if (option == 4)
        {
            handleCombinatorialCircuit();
        }
        else if (option == 5)
        {
            handleCircuitMinimization();
        }
        else if (option == 6)
        {
            break;
        }

        else
        {
            setColor(12);
            cout << "Invalid Input" << endl;
            handlePause();
        }
    }
    setColor(07);
    return 0;
}

void visualHeader()
{
    cout << "=====================================================" << endl;
    cout << "||     DIGITAL LOGIC CIRCUIT: VISUAL DESIGN        ||" << endl;
    cout << "=====================================================" << endl;
}
void header()
{
    system("cls");
    cout << " /$$$$$$$  /$$        /$$$$$$   /$$$$$$ " << endl;
    cout << "| $$__  $$| $$       /$$__  $$ /$$__  $$" << endl;
    cout << "| $$  \\ $$| $$      | $$  \\__/|$$  \\__/" << endl;
    cout << "| $$  | $$| $$      | $$      |  $$$$$$ " << endl;
    cout << "| $$  | $$| $$      | $$       \\____  $$" << endl;
    cout << "| $$  | $$| $$      | $$    $$ /$$  \\ $$" << endl;
    cout << "| $$$$$$$/| $$$$$$$$|  $$$$$$/|  $$$$$$/" << endl;
    cout << "|_______/ |________/ \\______/  \\______/ " << endl;
}
int handlePause()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nPress Enter to return to move forward...";
    cin.get();
    return 0;
}

bool NAND(bool a, bool b)
{
    return !(a && b);
}

bool NOR(bool a, bool b)
{
    return !(a || b);
}
bool AND(bool a, bool b)
{
    return a && b;
}
bool OR(bool a, bool b)
{
    return a || b;
}
bool NOT(bool a)
{
    return !a;
}
bool XOR(bool a, bool b)
{
    return a ^ b;
}
int checker(string number)
{
    bool valid = true;
    int tempNum = stoi(numValidation(number));
    while (valid)
    {
        if (tempNum != 0 && tempNum != 1)
        {
            cout << "Invalid Input just (1,0) are valid, Try again: ";
            cin >> number;
            tempNum = stoi(numValidation(number));
            valid = true;
        }
        else
        {
            valid = false;
        }
    }
    return tempNum;
}
string numValidation(string userInput)
{
    bool invalid = false;
    for (int i = 0; i < userInput.length(); i++)
    {
        if (!isdigit(userInput[i]))
        {
            invalid = true;
            break;
        }
    }
    while (invalid)
    {

        cout << "Invalid Input , input must be a bool(0,1)" << endl;
        cout << "Enter again: ";
        cin >> userInput;
        invalid = false;
        for (int i = 0; i < userInput.length(); i++)
        {
            if (!isdigit(userInput[i]))
            {
                invalid = true;
                break;
            }
        }
    }
    return userInput;
}
void headerOfTable()
{

    cout << "========================================================" << endl;
    cout << "||                    TRUTH TABLES                    ||" << endl;
    cout << "========================================================" << endl;
}
void menu()
{
    cout << "\n=====================================================" << endl;
    cout << "||           DIGITAL LOGIC SIMULATOR               ||" << endl;
    cout << "=====================================================" << endl;
    cout << "||  1. BASIC GATES (AND, OR, NOT, XOR,NAND,NOR)    ||" << endl;
    cout << "||  2. HALF-ADDER (2 Bits)                         ||" << endl;
    cout << "||  3. FULL-ADDER (3 Bits + Carry)                 ||" << endl;
    cout << "||  4. COMBINATIONAL CIRCUIT                       ||" << endl;
    cout << "||  5. CIRCUIT MINIMIZATION                        ||" << endl;
    cout << "||  6. EXIT                                        ||" << endl;
    cout << "=====================================================" << endl;
    cout << "Select an option: ";
}
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void handleBasicGates()
{
    int choice;
    bool num1, num2, carryIn;
    string temp;
    while (true)
    {
        setColor(11);
        header();
        cout << endl;
        setColor(13);
        cout << "=====================================================" << endl;
        cout << "||          BASIC GATES (AND, OR,...)              ||" << endl;
        cout << "=====================================================" << endl;
        setColor(12);
        cout << "1.AND GATE" << endl;
        cout << "2.OR GATE" << endl;
        cout << "3.NOT GATE" << endl;
        cout << "4.XOR GATE" << endl;
        cout << "5.NAND GATE" << endl;
        cout << "6.NOR GATE" << endl;
        cout << "7.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> temp;
        choice = stoi(numValidation(temp));
        if (choice == 1)
        {
            cout << "Enter number 1: ";
            cin >> temp;
            num1 = checker(temp);
            cout << "Enter number 2: ";
            cin >> temp;
            num2 = checker(temp);
            system("cls");
            cout << endl
                 << endl;
            cout << "P AND Q is: " << AND(num1, num2);
            cout << endl;
            setColor(13);
            visualHeader();
            setColor(12);
            cout << "\t  " << num1 << " -----\\ \n";
            cout << "\t          |----[ AND ]--- " << AND(num1, num2) << "\n"
                 << endl;
            cout << "\t  " << num2 << " -----/ \n";
            setColor(13);
            headerOfTable();
            cout << endl;
            setColor(12);
            cout << "+-------+-------+-------+" << endl;
            cout << "|   P   |   Q   |  P&Q  |" << endl;
            cout << "+-------+-------+-------+" << endl;

            for (int i = 0; i <= 1; i++)
            {
                for (int j = 0; j <= 1; j++)
                {
                    cout << "|   " << i << "   |   " << j << "   |   " << AND(i, j) << "   |" << endl;
                }
            }
            cout << "+-------+-------+-------+" << endl;
            cout << endl;
        }
        else if (choice == 2)
        {
            setColor(12);
            cout << "Enter number 1: ";
            cin >> temp;
            num1 = checker(temp);
            cout << "Enter number 2: ";
            cin >> temp;
            num2 = checker(temp);
            system("cls");
            cout << endl
                 << endl;
            cout << endl;
            cout << "P OR Q is: " << OR(num1, num2) << endl;
            setColor(13);
            visualHeader();
            setColor(12);
            cout << "\t  " << num1 << " -----|\\ \n";
            cout << "\t          | >---[ OR  ]--- " << OR(num1, num2) << "\n";
            cout << "\t  " << num2 << "-----|/ \n";
            cout << endl
                 << endl;
            setColor(13);
            headerOfTable();
            cout << endl
                 << endl;
            setColor(12);
            cout << "+-------+-------+-------+" << endl;
            cout << "|   P   |   Q   |  P||Q |" << endl;
            cout << "+-------+-------+-------+" << endl;

            for (int i = 0; i <= 1; i++)
            {
                for (int j = 0; j <= 1; j++)
                {
                    cout << "|   " << i << "   |   " << j << "   |   " << OR(i, j) << "   |" << endl;
                }
            }
            cout << "+-------+-------+-------+" << endl;
            cout << endl;
        }
        else if (choice == 3)
        {
            setColor(12);
            cout << "Enter number 1: ";
            cin >> temp;
            num1 = checker(temp);
            system("cls");
            cout << endl
                 << endl;
            cout << "!P is : " << NOT(num1) << endl;
            setColor(13);
            visualHeader();
            setColor(12);
            cout << endl
                 << endl;
            cout << "\t  " << num1 << " ----[ >o ]---- " << NOT(num1) << " (NOT)\n"
                 << endl;
            setColor(13);
            headerOfTable();
            setColor(12);
            cout << endl;
            cout << "+-------+-------+" << endl;
            cout << "|   P   |  !P   |" << endl;
            cout << "+-------+-------+" << endl;

            for (int i = 0; i <= 1; i++)
            {
                cout << "|   " << i << "   |   " << NOT(i) << "   |" << endl;
            }
            cout << "+-------+-------+" << endl;
        }
        else if (choice == 4)
        {
            setColor(12);
            cout << "Enter number 1: ";
            cin >> temp;
            num1 = checker(temp);
            cout << "Enter number 2: ";
            cin >> temp;
            num2 = checker(temp);
            system("cls");
            cout << endl
                 << endl;
            cout << "P XOR Q is: " << XOR(num1, num2) << endl;
            setColor(13);
            visualHeader();
            setColor(12);
            cout << "\t  " << num1 << " -----|\\ \n";
            cout << "\t          | >---[ XOR ]--- " << XOR(num1, num2) << "\n";
            cout << "\t  " << num2 << " -----|/ \n";
            cout << endl
                 << endl;
            setColor(13);
            headerOfTable();
            setColor(12);
            cout << endl
                 << endl;
            cout << "+-------+-------+-------+" << endl;
            cout << "|   P   |   Q   |  P^Q  |" << endl;
            cout << "+-------+-------+-------+" << endl;

            for (int i = 0; i <= 1; i++)
            {
                for (int j = 0; j <= 1; j++)
                {
                    cout << "|   " << i << "   |   " << j << "   |   " << XOR(i, j) << "   |" << endl;
                }
            }
            cout << "+-------+-------+-------+" << endl;
        }
        else if (choice == 5)
        {
            setColor(12);
            cout << "Enter number 1: ";
            cin >> temp;
            num1 = checker(temp);
            cout << "Enter number 2: ";
            cin >> temp;
            num2 = checker(temp);

            system("cls");
            cout << endl
                 << endl;
            cout << "P NAND Q is: " << NAND(num1, num2) << endl;

            setColor(13);
            visualHeader();
            setColor(12);
            cout << "\t  " << num1 << " -----\\ \n";
            cout << "\t          |----[ NAND ]o--- " << NAND(num1, num2) << "\n";
            cout << "\t  " << num2 << " -----/ \n";
            cout << endl
                 << endl;

            setColor(13);
            headerOfTable();
            setColor(12);
            cout << endl
                 << endl;
            cout << "+-------+-------+-------+" << endl;
            cout << "|   P   |   Q   | !(P&Q)|" << endl;
            cout << "+-------+-------+-------+" << endl;

            for (int i = 0; i <= 1; i++)
            {
                for (int j = 0; j <= 1; j++)
                {
                    cout << "|   " << i << "   |   " << j << "   |   " << NAND(i, j) << "   |" << endl;
                }
            }
            cout << "+-------+-------+-------+" << endl;
        }
        else if (choice == 6)
        {
            setColor(12);
            cout << "Enter number 1: ";
            cin >> temp;
            num1 = checker(temp);
            cout << "Enter number 2: ";
            cin >> temp;
            num2 = checker(temp);

            system("cls");
            cout << endl
                 << endl;
            cout << "P NOR Q is: " << NOR(num1, num2) << endl;

            setColor(13);
            visualHeader();
            setColor(12);
            cout << "\t  " << num1 << " -----|\\ \n";
            cout << "\t          | >o---[ NOR  ]--- " << NOR(num1, num2) << "\n";
            cout << "\t  " << num2 << " -----|/ \n";
            cout << endl
                 << endl;

            setColor(13);
            headerOfTable();
            setColor(12);
            cout << endl
                 << endl;
            cout << "+-------+-------+-------+" << endl;
            cout << "|   P   |   Q   | !(P||Q)|" << endl;
            cout << "+-------+-------+-------+" << endl;

            for (int i = 0; i <= 1; i++)
            {
                for (int j = 0; j <= 1; j++)
                {
                    cout << "|   " << i << "   |   " << j << "   |   " << NOR(i, j) << "   |" << endl;
                }
            }
            cout << "+-------+-------+-------+" << endl;
        }
        else if (choice == 7)
        {
            break;
        }

        else
        {
            setColor(12);
            cout << "Invalid Input" << endl;
        }
        handlePause();
    }
}
void handleFullAdder()
{
    bool num1, num2, carryIn;
    string temp;
    setColor(11);
    header();
    cout << endl;
    setColor(13);
    cout << "=====================================================" << endl;
    cout << "||                  FULL ADDER                     ||" << endl;
    cout << "=====================================================" << endl;
    setColor(12);
    cout << "Enter bit 1: ";
    cin >> temp;
    num1 = checker(temp);
    cout << "Enter bit 2: ";
    cin >> temp;
    num2 = checker(temp);
    cout << "Enter carryIn bit: ";
    cin >> temp;
    carryIn = checker(temp);
    bool sum = num1 ^ num2 ^ carryIn; // for sum we take exclusive OR
    bool part1 = num1 && num2;        // for carryOut first we have to find AND then exclusive OR of num1 and num2 then AND with carryIn bit , in last for answer I took OR
    bool part2 = (num1 ^ num2) && carryIn;
    bool carryOut = part1 || part2;
    system("cls");
    cout << endl;
    cout << "Resulting Sum: " << sum << endl;
    cout << "Resulting Carry-Out: " << carryOut << endl;
    setColor(13);
    cout << "=====================================================" << endl;
    cout << "||     DIGITAL LOGIC CIRCUIT: VISUAL DESIGN        ||" << endl;
    cout << "=====================================================" << endl;
    setColor(12);
    cout << "\n    --- Full-Adder Circuit ---" << endl;
    cout << "  " << num1 << " --------[ Half  ] \n";
    cout << "  " << num2 << " --------[ Adder ]----+ \n";
    cout << "                         |----[ Half  ]---- " << sum << "\n";
    cout << "  " << carryIn << " ---------------|----[ Adder ] \n";
    cout << "                         | \n";
    cout << "Carry_Part1 (" << part1 << ") -----------+----[  OR   ]---- " << carryOut << "\n";
    cout << "Carry_Part2 (" << part2 << ") ----------------[       ] \n";
    setColor(13);
    headerOfTable();
    cout << endl;
    setColor(12);
    cout << "+-------+-------+---------+-------+-------+" << endl;
    cout << "|   P   |   Q   | CARRYIN |  SUM  | CARRY |" << endl;
    cout << "+-------+-------+---------+-------+-------+" << endl;

    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            for (int s = 0; s <= 1; s++)
            {
                bool sum = i ^ j ^ s;
                bool part1 = i && j;
                bool part2 = (i ^ j) && s;
                bool carryOut = part1 || part2;

                cout << "|   " << i << "   |   " << j << "   |    " << s << "    |   " << sum << "   |   " << carryOut << "   |" << endl;
            }
        }
    }
    cout << "+-------+-------+---------+-------+-------+" << endl;
    handlePause();
}
void handleCombinatorialCircuit()
{
    string temp;
    setColor(11);
    header();
    cout << endl;
    setColor(13);
    cout << "=====================================================" << endl;
    cout << "||              COMBINATIONAL CIRCUIT              ||" << endl;
    cout << "=====================================================" << endl;
    bool a, b, c;
    int choice;
    setColor(12);
    cout << "Enter Bit A: ";
    cin >> temp;
    a = checker(temp);
    cout << "Enter Bit B: ";
    cin >> temp;
    b = checker(temp);
    cout << "Enter Bit C: ";
    cin >> temp;
    c = checker(temp);
    setColor(12);
    while (true)
    {
        system("cls");
        setColor(12);
        setColor(13);
        cout << "=====================================================" << endl;
        cout << "||               Combinatorial Circuits             ||" << endl;
        cout << "=====================================================" << endl;
        setColor(12);
        cout << "\nChoose a Combinational Circuit Recipe:\n";
        cout << "1. Circuit (P AND Q) OR R\n";
        cout << "2. Circuit Logic (P XOR Q) AND R\n";
        cout << "3. Circuit Gate (P OR Q) AND R\n";
        cout << "4. Exit\n";
        cout << "Selection: ";
        cin >> choice;

        if (choice == 1)
        {
            bool step1 = AND(a, b);
            bool finalResult = OR(step1, c);
            system("cls");
            cout << endl;
            setColor(13);
            cout << "=====================================================" << endl;
            cout << "||               (P AND Q) OR R                     ||" << endl;
            cout << "=====================================================" << endl;
            setColor(12);
            cout << "Result: " << finalResult << endl;
            cout << "  " << a << " -----\\ \n";
            cout << "          |----[ AND ]----( " << step1 << " )---\\ \n";
            cout << "  " << b << " -----/                        |----[ OR ]--- OUT: " << finalResult << "\n";
            cout << "                            " << c << " ----/ \n";
            cout << endl;
            cout
                << endl;
            setColor(13);
            headerOfTable();
            cout
                << endl;
            setColor(12);
            cout << "+-------+-------+-------+------------+" << endl;
            cout << "|   P   |   Q   |   R   | P&Q OR R   |" << endl;
            cout << "+-------+-------+-------+------------+" << endl;

            for (int i = 0; i <= 1; i++)
            {
                for (int j = 0; j <= 1; j++)
                {
                    for (int k = 0; k <= 1; k++)
                    {
                        bool part1 = AND(i, j);
                        bool part2 = OR(part1, k);
                        cout << "|   " << i << "   |   " << j << "   |   " << k << "   |      " << part2 << "     |" << endl;
                    }
                }
            }
            cout << "+-------+-------+-------+------------+" << endl;
            cout << endl;
        }
        else if (choice == 2)
        {
            bool step1 = XOR(a, b);
            bool finalResult = AND(step1, c);
            system("cls");
            cout << endl;
            setColor(13);
            cout << "=====================================================" << endl;
            cout << "||                (P XOR Q) OR R                   ||" << endl;
            cout << "=====================================================" << endl;
            setColor(12);
            cout << "Result: " << finalResult << endl;
            cout << "  A -----\\ \n";
            cout << "          |----[ XOR ]----( " << step1 << " )---\\ \n";
            cout << "  B -----/                        |----[ AND ]--- OUT: " << finalResult << "\n";
            cout << "                            C ----/ \n";

            cout << endl
                 << endl;
            setColor(13);
            headerOfTable();
            cout << endl
                 << endl;
            setColor(12);
            cout << "+-------+-------+-------+--------------+" << endl;
            cout << "|   P   |   Q   |   R   |  (P^Q) AND R |" << endl;
            cout << "+-------+-------+-------+--------------+" << endl;

            for (int i = 0; i <= 1; i++)
            {
                for (int j = 0; j <= 1; j++)
                {
                    for (int k = 0; k <= 1; k++)
                    {
                        bool part1 = XOR(i, j);
                        bool part2 = AND(part1, k);
                        cout << "|   " << i << "   |   " << j << "   |   " << k << "   |       " << part2 << "      |" << endl;
                    }
                }
            }
            cout << "+-------+-------+-------+--------------+" << endl;
            cout << endl;
        }
        else if (choice == 3)
        {
            bool step1 = OR(a, b);
            bool finalResult = AND(step1, c);
            system("cls");
            cout << endl;
            setColor(13);
            cout << "=====================================================" << endl;
            cout << "||                (P OR Q) AND R                   ||" << endl;
            cout << "=====================================================" << endl;
            setColor(12);
            cout << "Result: " << finalResult << endl;
            cout << "  " << a << " -----|\\ \n";
            cout << "          | >---[ OR  ]----( " << step1 << " )---\\ \n";
            cout << "  " << b << " -----|/                        |----[ AND ]--- OUT: " << finalResult << "\n";
            cout << "                            " << c << " ----/ \n";

            cout
                << endl;
            setColor(13);
            headerOfTable();
            cout
                << endl;
            setColor(12);
            cout << "+-------+-------+-------+----------------+" << endl;
            cout << "|   P   |   Q   |   R   |  (P||Q) AND R  |" << endl;
            cout << "+-------+-------+-------+----------------+" << endl;

            for (int i = 0; i <= 1; i++)
            {
                for (int j = 0; j <= 1; j++)
                {
                    for (int k = 0; k <= 1; k++)
                    {
                        bool part1 = OR(i, j);
                        bool part2 = AND(part1, k);
                        cout << "|   " << i << "   |   " << j << "   |   " << k << "   |       " << part2 << "        |" << endl;
                    }
                }
            }
            cout << "+-------+-------+-------+----------------+" << endl;
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            setColor(12);
            cout << "Invalid Input";
        }
        handlePause();
    }
}
void handleCircuitMinimization()
{
    int minChoice;
    while (true)
    {
        viewMinimizationMenu();
        cin >> minChoice;

        if (minChoice == 1)
        {
            viewBooleanAlgebra();
        }
        else if (minChoice == 2)
        {
            MinimizationExample();
        }
        else if (minChoice == 3)
        {
            MinimizationLawVerifier();
        }
        else if (minChoice == 4)
        {
            break;
        }
    }
}

void handleHalfAdder()
{

    bool num1, num2;
    string temp;
    setColor(11);
    header();
    cout << endl;
    setColor(13);
    cout << "=====================================================" << endl;
    cout << "||                  HALF ADDER                     ||" << endl;
    cout << "=====================================================" << endl;
    setColor(12);
    cout << "Enter Bit A (0 or 1): ";
    cin >> temp;
    num1 = checker(temp);
    cout << "Enter Bit B (0 or 1): ";
    cin >> temp;
    num2 = checker(temp);
    bool sum = (num1 != num2); // XOR logic
    bool carry = (num1 && num2);
    system("cls");
    cout << endl; // AND logic
    cout << "Half-Adder Result -> Sum: " << sum << ", Carry: " << carry << endl;
    setColor(13);
    visualHeader();
    setColor(12);
    cout << "\n    --- Half-Adder Circuit ---" << endl;
    cout << "    Input A (" << num1 << ") ----+----[ XOR ]---- SUM: " << sum << endl;
    cout << "                   | " << endl;
    cout << "    Input B (" << num2 << ") --+--+----[ AND ]---- CARRY: " << carry << endl;
    setColor(13);
    headerOfTable();
    setColor(12);
    cout << endl
         << endl;
    setColor(12);
    cout << "+-------+-------+-------+-------+" << endl;
    cout << "|   P   |   Q   |  SUM  | CARRY |" << endl;
    cout << "+-------+-------+-------+-------+" << endl;

    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            bool sum = (i != j);
            bool carry = (i && j);
            cout << "|   " << i << "   |   " << j << "   |   " << sum << "   |   " << carry << "   |" << endl;
        }
    }
    cout << "+-------+-------+-------+-------+" << endl;
    handlePause();
}
void viewMinimizationMenu()
{
    setColor(11);
    header();
    cout << endl;
    setColor(13);
    cout << "=====================================================" << endl;
    cout << "||           CIRCUIT MINIMIZATION TOOLS            ||" << endl;
    cout << "=====================================================" << endl;
    setColor(12);
    cout << "1. View Boolean Algebra Laws" << endl;
    cout << "2. Minimization Example (Visual + Truth Table)" << endl;
    cout << "3. Live Law Verifier (Verify Multiple Laws)" << endl;
    cout << "4. Return to Main Menu" << endl;
    cout << "Selection: ";
}
void viewBooleanAlgebra()
{
    system("cls");
    setColor(13);
    cout << "=====================================================" << endl;
    cout << "||               Boolean Algebra Laws              ||" << endl;
    cout << "=====================================================" << endl;
    setColor(12);
    cout << "--- KEY BOOLEAN LAWS ---" << endl;
    cout << "1. Identity:  A + 0 = A  |  A . 1 = A" << endl;
    cout << "2. Annulment: A + 1 = 1  |  A . 0 = 0" << endl;
    cout << "3. Complement:A + A' = 1 |  A . A' = 0" << endl;
    cout << "4. De Morgan: (A.B)' = A' + B'" << endl;
    handlePause();
}
void MinimizationExample()
{
    system("cls");
    setColor(13);
    cout << "=====================================================" << endl;
    cout << "||               Minimization Example               ||" << endl;
    cout << "=====================================================" << endl;
    setColor(12);
    cout << "EXPRESSION: (A AND B) OR (A AND NOT B)" << endl;
    cout << "MINIMIZED TO: A" << endl;
    cout << "---------------------------------------" << endl;
    cout << "COMPLEX CIRCUIT:             MINIMIZED:" << endl;
    cout << "A --|\\                       A -------- OUT" << endl;
    cout << "    | AND --|\\ " << endl;
    cout << "B --|/      |        " << endl;
    cout << "            | OR --- OUT" << endl;
    cout << "A --|\\      |        " << endl;
    cout << "    | AND --|/       " << endl;
    cout << "B'--|/               " << endl;
    setColor(13);
    cout << "\n--- PROOF BY TRUTH TABLE ---" << endl;
    cout << "A\tB\t(A.B)+(A.B')\tMinimized(A)" << endl;
    cout << "--------------------------------------------" << endl;
    setColor(12);
    cout << "+-------+-------+-----------------+----------------+" << endl;
    cout << "|   P   |   Q   | (P&Q) OR (P&!Q) | SIMPLIFIED (P) |" << endl;
    cout << "+-------+-------+-----------------+----------------+" << endl;

    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            bool complex = (i && j) || (i && !j);
            bool simple = i;
            cout << "|   " << i << "   |   " << j << "   |        " << complex << "        |        " << simple << "       |" << endl;
        }
    }
    cout << "+-------+-------+-----------------+----------------+" << endl;
    cout << "\nRESULT: Both columns match exactly!" << endl;
    handlePause();
}
void MinimizationLawVerifier()
{
    string temp;
    system("cls");
    int lawType;
    setColor(13);
    cout << "=====================================================" << endl;
    cout << "||                   Verify laws                   ||" << endl;
    cout << "=====================================================" << endl;
    setColor(4);
    cout << "Choose a Law to Verify Live:\n";
    cout << "1. Absorption (A + AB = A)\n";
    cout << "2. Identity   (A + 0 = A)\n";
    cout << "3. Idempotent (A + A = A)\n";
    cout << "Selection: ";
    cin >> lawType;
    setColor(12);
    bool a, b, complexSide, simpleSide;
    cout << "Enter Bit A (0 or 1): ";
    cin >> temp;
    a = checker(temp);

    if (lawType == 1)
    {
        cout << "Enter Bit B (0 or 1): ";
        cin >> temp;
        b = checker(temp);
        complexSide = (a || (a && b));
        simpleSide = a;
    }
    else if (lawType == 2)
    {
        complexSide = (a || 0);
        simpleSide = a;
    }
    else if (lawType == 3)
    {
        complexSide = (a || a);
        simpleSide = a;
    }

    setColor(12);
    cout << "\nComplex Result: " << complexSide << endl;
    cout << "Simple Result:  " << simpleSide << endl;
    if (complexSide == simpleSide)
        cout << "VERDICT: SUCCESS! Logic is minimized." << endl;
    handlePause();
}