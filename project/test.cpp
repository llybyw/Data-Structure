#include<iostream>
#include<string>
#include<vector>
#include "expression_evaluator.h" 

using namespace std;

int main() {
    Calculator cal; // 创建计算器对象
    string expr;    // 用于存储表达式

    expr = "2*(1+3)-5*(15.23)/(1+2)*3-5";
    cout << "input1:  " << expr << endl;
    cal.parse(expr);
    cout << "output1: ";
    cal.solve();

    expr = "1.25+(3*(1+2)*3-43)/(4-2)";
    cout << "input2:  " << expr << endl;
    cal.parse(expr);
    cout << "output2: ";
    cal.solve();

    expr = "-1.25+(-3*(1+2)*3-43*(-0.5))/(4-2)";
    cout << "input3:  " << expr << endl;
    cal.parse(expr);
    cout << "output3: ";
    cal.solve();

    expr = "2*(1+3))-5*(15.23)/(1+2)*3-5";
    cout << "input4:  " << expr << endl;
    cal.parse(expr);
    cout << "output4: ";
    cal.solve();

    expr = "2*(1+3)-5*(15.23)/(1-1)*3-5";
    cout << "input5:  " << expr << endl;
    cal.parse(expr);
    cout << "output5: ";
    cal.solve();

    expr = "2*(1+3)-5*(15.23)(1+2)*3-5";
    cout << "input6:  " << expr << endl;
    cal.parse(expr);
    cout << "output6: ";
    cal.solve();

    expr = "2*(1+3)()-5*(15.23)/(1+2)*3-5";
    cout << "input7:  " << expr << endl;
    cal.parse(expr);
    cout << "output7: ";
    cal.solve();

    expr = "2*(1+3c)-5*(15.2z3)/(1+x2)*3-5";
    cout << "input8:  " << expr << endl;
    cal.parse(expr);
    cout << "output8: ";
    cal.solve();

    expr = "2*(1+3)-5*(15.2.3)/(1+2)*3-5";
    cout << "input9:  " << expr << endl;
    cal.parse(expr);
    cout << "output9: ";
    cal.solve();

    expr = "2*(1+3)-5*(15.23)/(1+2)+*3-5";
    cout << "input10:  " << expr << endl;
    cal.parse(expr);
    cout << "output10: ";
    cal.solve();

    return 0;
}