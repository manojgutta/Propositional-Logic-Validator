#include <iostream>
#include <string>
#include <stack>
using namespace std;
/// @brief This function is used for the verification of the proof rule "and Introduction"
/// @param str this is the string type array passed on the from the main function
/// @param store this is the string used to store the input lines passed on from the main function
/// @param initial it is used to store the first premise line no. extractred from the rule declatration
/// @param final it is used to store the  second premise line no. extractred from the rule declatration
/// @return It returns the truth value the proof statments for andIntroduction rule.
bool andIntroduction(string str[], string store, int initial, int final)
{
    string combinedString = str[initial - 1] + "*" + str[final - 1];
    string originalLine = store.substr(1, store.find("/") - 2);
    if (combinedString.compare(originalLine) == 0)
        return true;
    else
        return false;
}

/// @brief This function is used for the verification of the proof rule "and elimination1"
/// @param str this is the string type array passed on the from the main function
/// @param store this is the string used to store the input lines input lines passed on from the main function
/// @param position it is used to store the premise line no. extractred from the rule declatration
/// @return It returns the truth value the proof statments for andElimination1 rule.
bool andElimination1(string str[], string store, int position)
{
    string PreLine = str[position - 1];
    stack<string> st;
    string generate;
    int count = 0;
    for (int i = 0; i < PreLine.length(); i++)
    {
        if (PreLine[i] == '(')
            count += 1;
    }

    cout << count << endl;
    if (count > 1)
    {
        for (int i = 1; i < PreLine.length(); i++)
        {
            if (PreLine[i] == '(')
            {
                st.push("(");
                generate += "(";
            }
            else if (PreLine[i] == ')')
            {
                st.pop();
                generate += ")";
                if (st.empty())
                    break;
            }
            else
                generate += PreLine[i];
        }
        string ruleLine = store.substr(0, store.find("/"));
        if (ruleLine.compare(generate) == 0)
            return true;
        else
            return false;
    }
    else
    {
        string s1 = PreLine.substr(1, PreLine.find("*") - 1);
        string s2 = store.substr(0, store.find("/"));
        if (s2.compare(s1) == 0)
            return true;
    }
    return false;
}

/// @brief This function is used for the verification of the proof rule "and elimination2"
/// @param str this is the string type array passed on the from the main function
/// @param store this is the string used to store the input lines input lines passed on from the main function
/// @param position it is used to store the premise line no. extractred from the rule declatration
/// @return It returns the truth value the proof statments for andElimination2 rule.
bool andElimination2(string str[], string store, int position)
{
    string preLine = str[position - 1];
    stack<string> st;
    string generate;
    int count = 0;
    for (int i = 0; i < preLine.length(); i++)
    {
        if (preLine[i] == '(')
            count += 1;
    }
    if (count > 1)
    {
        int cp = 0;
        for (int i = 1; i < preLine.length(); i++)
        {
            if (preLine[i] == '(')
            {
                st.push("(");
                generate += "(";
                cp++;
            }
            else if (preLine[i] == ')')
            {
                st.pop();
                generate += ")";
                cp++;
                if (st.empty())
                    break;
            }
            else
            {
                generate += preLine[i];
                cp++;
            }
        }
        int y = preLine.length() - generate.length() - 3;
        string s1 = preLine.substr(cp + 2, y);
        string s2 = store.substr(0, store.find("/"));
        cout << s1 << endl
             << s2 << endl;
        if (s2.compare(s1) == 0)
            return true;
    }
    else
    {
        string s1 = preLine.substr(preLine.find("*") + 1, preLine.length() - generate.length() - 4);
        string s2 = store.substr(0, store.find("/"));
        if (s2.compare(s1) == 0)
            return true;
    }
    return false;
}
/// @brief This function is used for the verification of the proof rule "or introduction 1"
/// @param str This is the string type array passed on the from the main function
/// @param store this is the string used to store the input lines input lines passed on from the main function
/// @param position it is used to store the premise line no. extractred from the rule declatration
/// @return  It returns the truth value the proof statments for or introduction 1 rule.
bool orIntroduction1(string str[], string store, int position)
{
    string preLine = str[position - 1];
    preLine = "(" + preLine + "+";
    bool f = true;
    for (int i = 0; i < preLine.length(); i++)
    {
        if (preLine[i] != store[i])
        {
            f = false;
            break;
        }
    }
    if (f == false)
        return false;
    return true;
}

/// @brief This function is used for the verification of the proof rule "or introduction 2"
/// @param str This is the string type array passed on the from the main function
/// @param store this is the string used to store the input lines input lines passed on from the main function
/// @param position it is used to store the premise line no. extractred from the rule declatration
/// @return  It returns the truth value the proof statments for or introduction 2 rule.
bool orIntroduction2(string str[], string store, int position)
{
    string preLine = str[position - 1];
    preLine = "+" + preLine + ")";
    int index = store.find("/");
    int c = preLine.length() - 1;
    for (int i = index - 1; i >= index - preLine.length(); i--)
    {
        if (preLine[c] != store[i])
        {
            return false;
        }
        c--;
    }
    return true;
}
/// @brief This function is used for the verification of the proof rule "implication elimination"
/// @param str This is the string type array passed on the from the main function
/// @param store this is the string used to store the input lines input lines passed on from the main function
/// @param position1 It is used to store the first premise line no. extractred from the rule declatration
/// @param position2 It is used to store the  second premise line no. extractred from the rule declatration
/// @return It returns the truth value the proof statments for implication elimination rule.
bool implicationElimination(string str[], string store, int position1, int position2)
{
    string firstLine = str[position1 - 1];
    string secondLine = str[position2 - 1];
    firstLine = "(" + firstLine + ">";
    bool f = true;

    for (int i = 0; i < firstLine.length(); i++)
    {
        if (firstLine[i] != secondLine[i])
        {
            f = false;
            break;
        }
    }
    if (f == false)
        return false;
    string cmpr = "";
    for (int i = firstLine.length(); i < secondLine.length() - 1; i++)
    {
        cmpr += secondLine[i];
    }
    string cmpr1 = store.substr(0, store.find("/"));

    if (cmpr1.compare(cmpr) == 0)
        return true;
    return false;
}

/// @brief This function is used for the verification of the proof rule "Modus Tollens"
/// @param str This is the string type array passed on the from the main function
/// @param store this is the string used to store the input lines input lines passed on from the main function
/// @param position1 It is used to store the first premise line no. extractred from the rule declatration
/// @param position2 It is used to store the  second premise line no. extractred from the rule declatration
/// @return It returns the truth value the proof statments for Modus Tollens rule.
bool modusTollens(string str[], string store, int position1, int position2)
{
    string firstLine = str[position1 - 1];
    string secondLine = str[position2 - 1];
    int a = 0;
    bool flag = true;
    int counter = firstLine.length() - 1;
    int pp = 0;

    for (int i = 0; i < secondLine.length(); i++)
    {
        if (secondLine[i] == '~')
            a++;
    }
    if (a == 2)
    {
        for (int i = secondLine.length() - 1; i >= 2; i--)
        {
            cout << firstLine[counter] << "  " << secondLine[i] << endl;
            if (firstLine[counter] != secondLine[i])
            {
                flag = false;
                break;
            }
            counter--;
        }
        if (flag == false)
            return false;
    }
    else if (a == 1)
    {
        for (int i = 2; i < secondLine.length() - 1; i++)
        {
            pp++;
        }
        if (pp > 1)
            secondLine += ")";

        for (int i = secondLine.length() - 1; i >= 2; i--)
        {
            if (firstLine[counter] != secondLine[i])
            {
                flag = false;
                break;
            }
            counter--;
        }
        if (flag == false)
            return false;
        if (pp > 1)
            counter--;
        if (firstLine[counter] != '>')
            return false;
    }
    else if (a == 0)
    {
        return false;
    }
    else
        return false;
    stack<string> st;
    string cmpr;
    int count = 0;
    for (int i = 0; i < firstLine.length(); i++)
    {
        if (firstLine[i] == '(')
            count += 1;
    }
    if (count > 1)
    {
        for (int i = 1; i < firstLine.length(); i++)
        {
            if (firstLine[i] == '(')
            {
                st.push("(");
                cmpr += "(";
            }
            else if (firstLine[i] == ')')
            {
                st.pop();
                cmpr += ")";
                if (st.empty())
                    break;
            }
            else
                cmpr += firstLine[i];
        }
        cmpr = "~" + cmpr;

        string cmpr1 = store.substr(0, store.find("/"));

        if (cmpr1.compare(cmpr) == 0)
            return true;
        return false;
    }
    return true;
}
/// @brief  Here we are reading the no.of input lines aswell as the proofstatements and passing them to the respective proof check functions
/// @return it returns zero(default integer value)
int main()
{
    int lines = 0;
    cout << "Enter the number of proof lines" << endl;
    cin >> lines;
    string input[lines];
    cout << "Enter the proof" << endl;
    bool flag = true;
    for (int i = 0; i < lines; i++)
    {
        string store = "";
        cin >> store;
        // the strings in the if are for storing the line numbers in them and later converting them to int
        if (store.find("P") < 100)
        {
            input[i] += store.substr(0, store.find("/"));
        }
        else if (store.find("*i") < 100)
        {
            string s1;
            string s2;
            s1 += store[store.find("*i") + 3];
            int initial = stoi(s1);
            s2 += store[store.find("*i") + 5];
            int final = stoi(s2);
            flag = andIntroduction(input, store, initial, final);
            if (flag == false)
                break;
            input[i] += store.substr(0, store.find("/"));
        }
        else if (store.find("*e1") < 100)
        {
            string s1;
            s1 += store[store.find("*e1") + 4];
            int c1 = stoi(s1);
            flag = andElimination1(input, store, c1);
            if (flag == false)
                break;
            input[i] += store.substr(0, store.find("/"));
        }
        else if (store.find("*e2") < 100)
        {
            string s1;
            s1 += store[store.find("*e2") + 4];
            int c1 = stoi(s1);
            flag = andElimination2(input, store, c1);
            if (flag == false)
                break;
            input[i] += store.substr(0, store.find("/"));
        }
        else if (store.find("+i1") < 100)
        {
            string s1;
            s1 += store[store.find("+i1") + 4];
            int c1 = stoi(s1);
            flag = orIntroduction1(input, store, c1);
            if (flag == false)
                break;
            input[i] += store.substr(0, store.find("/"));
        }
        else if (store.find("+i2") < 100)
        {
            string s1;
            s1 += store[store.find("+i2") + 4];
            int c1 = stoi(s1);
            flag = orIntroduction2(input, store, c1);
            if (flag == false)
                break;
            input[i] += store.substr(0, store.find("/"));
        }
        else if (store.find(">e") < 100)
        {
            string s1;
            string s2;
            s1 += store[store.find(">e") + 3];
            int c1 = stoi(s1);
            s2 += store[store.find(">e") + 5];
            int c2 = stoi(s2);
            flag = implicationElimination(input, store, c2, c1);
            if (flag == false)
                break;
            input[i] += store.substr(0, store.find("/"));
        }
        else if (store.find("MT") < 100)
        {
            string s1;
            string s2;
            s1 += store[store.find("MT") + 3];
            int c1 = stoi(s1);
            s2 += store[store.find("MT") + 5];
            int c2 = stoi(s2);
            flag = modusTollens(input, store, c1, c2);
            if (flag == false)
                break;
            input[i] += store.substr(0, store.find("/"));
        }
        else
        {
            cout << "Your input is invalid we'll terminate the program here." << endl;
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "The proof entered is a valid one";
    else
        cout << "Invalid proof";
    return 0;
}