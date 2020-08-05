using namespace std;

// My convert string to integer.
int myConStrInt(string &str) {
    int num = 0;
    int lengStr = str.length();
    for (int i = 0; i < lengStr; i++) {
        num = num*10 + str[i] - 0x30;
    }
    return num;
}

// This is my defensive code for input basic data types.
void myInput(int &varInput,
string userMessage = "Введите целое: ",
string errorMessage = "Ошибка ввода.") {

    while (true) {
        cout << userMessage;
	    cin >> varInput;

	    if (cin.peek() == '\n') {
	        cin.get();
	        break;
	    } else {
	        cout << "\n" << errorMessage << endl;
	        cin.clear();
	        while (cin.get() != '\n') {};
	    }
    }
}

void myInput(float &varInput,
string userMessage = "Введите действительное: ",
string errorMessage = "Ошибка ввода.") {

    while (true) {
	    cout << userMessage;
	    cin >> varInput;

	    if (cin.peek() == '\n') {
	        cin.get();
	        break;
	    } else {
	        cout << "\n" << errorMessage << endl;
            cin.clear();
	        while (cin.get() != '\n') {};
	    }
    }
}

void myInput(char &varInput,
string userMessage = "Введите символ: ",
string errorMessage = "Ошибка ввода.") {

    while (true) {
	    cout << userMessage;
	    cin >> varInput;

	    if (cin.peek() == '\n') {
	        cin.get();
	        break;
	    } else {
	        cout << "\n" << errorMessage << endl;
            cin.clear();
	        while (cin.get() != '\n') {};
	    }
    }
}

void myInput(string &varInput,
string userMessage = "Введите слово: ",
string errorMessage = "Ошибка ввода.") {

    while (true) {
        cout << userMessage;
	    cin >> varInput;

	    if (cin.peek() == '\n') {
	        cin.get();
	        break;
	    } else {
	        cout << "\n" << errorMessage << endl;
	        cin.clear();
	        while (cin.get() != '\n') {};
	    }
    }
}
