#include "utilities.hpp"
int tmpval = 1;
String intToString(int in)
{
    String temp;
    int t = 0;
    while (in != 0)
    {
        temp += (in % 10) + '0';
        in /= 10;
        t++;
    }
    String out;
    for (int i = temp.length() - 1; i >= 0; i--) out += temp[i];
    return out;
}

String nextToken(std::istream& in)
{
    String temp;
    char c;
    while (in.get(c) && c != ' ')
    {
        if (in.eof()) break;
        temp += c;
        if (c == ';')
        {
            return temp;
        }
    }
    return temp;
}

String infixToPostfix(std::istream& in) 
{
    stack<String> s;
    String token = nextToken(in);
    while (token != ";")
    {
        if(in.eof()) return "END_OF_FILE";
        if(token == ")")
        {
            String right = s.pop();
            String oper = s.pop();
            String left = s.pop();
            s.push(left + right + oper);
        }
        else
        {
            if (token != "(") s.push(token + " ");
        }
        token = nextToken(in);
    }
    return s.top().substr(0, s.top().length() - 2);
}

String postfixToAssembly(String expr, std::ostream& out)
{
    std::vector<String> tokens = expr.split(' ');
    stack<String> stck;
    for(String s : tokens)
    {
        if (!(s == "+" || s == "-" || s == "*" || s == "/"))
        {
            stck.push(s);
        }
        else
        {
            String right = stck.pop();
            String left = stck.pop();
            stck.push(evaluate(left, s, right, out));
        }
    }
    tmpval = 1;
    return stck.top(); //returns the reuslt of the expression... kinda pointless
}

String evaluate(String left, String op, String right, std::ostream& out)
{
    out << "   LD     " << left << std::endl;
    if(op == "+") 
    {
        out << "   AD     " << right << std::endl;
    }
    if(op == "-") 
    {
        out << "   SB     " << right << std::endl;
    }
    if(op == "/")
    {
        out << "   DV     " << right << std::endl;
    } 
    if(op == "*")
    {
        out << "   MU     " << right << std::endl;
    }
    String temp = "TMP" + intToString(tmpval);
    tmpval++;
    out << "   ST     " << temp << std::endl;
    return temp;
}