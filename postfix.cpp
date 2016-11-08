#include"Header.h"

void postfix_count(string exp, float* arr, string letters)
{
	float num1, num2;
	string num;
	bool flag = true;
	Stack<float> *stack = nullptr, *elem = nullptr;
	for (int i = 0; i < exp.length(); i++)
	{
		num = "";
		if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z')
		{
			stack->Push(stack, arr[letters.find(tolower(exp[i]))]);
		}
		if (exp[i] >= '0' && exp[i] <= '9')
		{
			while (exp[i] >= '0' && exp[i] <= '9' || exp[i] == ',') // stof в данном случае преобразовывает числа вида 2,6, а не 2.6. Видимо из-за расскладки.
			{
				num += exp[i++];
			}
			stack->Push(stack, stof(num));
			--i;
		}
		if (exp[i] == '+')
		{
			num2 = stack->Pop(stack)->key;
			num1 = stack->Pop(stack)->key;
			stack->Push(stack, num1 + num2);
		}
		if (exp[i] == '-')
		{
			num2 = stack->Pop(stack)->key;
			num1 = stack->Pop(stack)->key;
			stack->Push(stack, num1 - num2);
		}
		if (exp[i] == '*')
		{
			num2 = stack->Pop(stack)->key;
			num1 = stack->Pop(stack)->key;
			stack->Push(stack, num1 * num2);
		}
		if (exp[i] == '/')
		{
			num2 = stack->Pop(stack)->key;
			num1 = stack->Pop(stack)->key;
			if (num2 != 0)
				stack->Push(stack, num1 / num2);
			else
			{
				cout << "Неможливо виконати операцію через ділення на 0.\n";
				flag = false;
				break;
			}
		}
		//Print(stack);
	}
	if (flag == true)
		cout << "Результат роботи програми: " << stack->Pop(stack)->key << endl;
}
template <class T> Stack<T>::Stack()
{
	next = nullptr;
}
template <class T> Stack<T>::~Stack()
{
	if (this != nullptr)
	{
		if (this->next != nullptr)
			delete this->next;
		next = nullptr;
	}
}
template <class T> Stack<T>* Stack<T>::Pop(Stack<T> *&stack)
{
	if (stack == nullptr)
	{
		cout << "\nСтек порожній.\n";
		return nullptr;
	}
	Stack* elem = stack;
	stack = stack->next;
	elem->next = nullptr;
	return elem;
}
template <class T> void Stack<T>::Push(Stack<T> *&stack, T elem)
{
	Stack* newElem = new Stack;
	newElem->key = elem;
	newElem->next = stack;
	stack = newElem;
}
int priority(char a)
{
	switch (a)
	{
	case '*': return 3;
	case '/': return 3;
	case '+': return 2;
	case '-': return 2;
	case ')': return 1;
	case '(': return 0;
	}
}
string postfix(string exp1, int &num)
{
	string exp2 = "";
	Stack<char> *stack = nullptr;
	for (int i = 0; i < exp1.length(); i++)
	{
		if (exp1[i] >= 'a' && exp1[i] <= 'z' || exp1[i] >= 'A' && exp1[i] <= 'Z')
		{
			exp2 += exp1[i];
			num++;
		}
		if (exp1[i] >= '0' && exp1[i] <= '9')
		{
			exp2 += exp1[i];
		}
		if (exp1[i] == ' ')
		{
			while (exp1[i] == ' ') i++;
			i--;
		}
		if (exp1[i] == ',' && exp1[i - 1] >= '0' && exp1[i-1] <= '9')
		{
			exp2 += exp1[i];
		}
		if (exp1[i] == '.' && exp1[i - 1] >= '0' && exp1[i - 1] <= '9')
		{
			exp2 += ',';
		}
		if (exp1[i] == '(')
			stack->Push(stack, exp1[i]);
		if (exp1[i] == ')')
		{
			while (stack != nullptr && stack->key != '(')
			{
				exp2 += stack->Pop(stack)->key;
			}
			if (stack == nullptr)
			{
				cout << "Помилка вводу. Перевірте, будь ласка, правильність введеного виразу.\n\n";
				return "";
			}
			else stack->Pop(stack);
		}
		else if (exp1[i] == '+' || exp1[i] == '-' || exp1[i] == '*' || exp1[i] == '/')
		{
			while (stack != nullptr && priority(exp1[i]) <= priority(stack->key))
			{
				exp2 += stack->Pop(stack)->key;
			}
			stack->Push(stack, exp1[i]);
		}
		//Print(stack);
	}
	while (stack != nullptr)
	{
		if (stack->key == '(')
		{
			cout << "Помилка вводу. Перевірте, будь ласка, правильність введеного виразу.\n\n";
			return "";
		}
		exp2 += stack->Pop(stack)->key;
	}
	return exp2;
}
template <class T> void Print(Stack<T>* stack)
{
	if (stack == nullptr) cout << "\nСтек порожній.\n";
	else
	{
		cout << "\nСтек: ";
		while (stack != nullptr)
		{
			cout << stack->key << " ";
			stack = stack->next;
		}
		cout << endl;
	}
}
