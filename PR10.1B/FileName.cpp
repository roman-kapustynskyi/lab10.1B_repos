#include<iostream>
#include<iomanip>
#include<string>
#include <Windows.h>
using namespace std;
enum Spec{KN,INF,ME,FI,TN};

struct Student {
	string prizv;
	int kurs;
	Spec spec;
	int fizyka;
	int matematika;
	union {
		int prog;
		int chys_metody;
		int pedagogika;
	};
};
void Create(Student* p , const int N)
{
	for (int i = 0;i < N;i++) {
		cout << "Student№ " << i + 1<<endl;
		cin.ignore();
		cout << "прізвище ";
		getline(cin, p[i].prizv);
		cout << "курс";
		cin >> p[i].kurs;
		cout << "0 - КН, 1 - Інформатика, 2 - МЕ, 3 - ФІ, 4 - ТН";
		int x;
		cin >> x;
		while (x < 0 || x > 4) {
			cout << "Помилка! Введіть число від 0 до 4: ";
			cin >> x;
		}
		p[i].spec = (Spec)x;
		cout << "фізика ";
		cin >> p[i].fizyka;
		cout << "математика ";
		cin >> p[i].matematika;
		
		switch (p[i].spec) {
		case KN:
			cout << " з програмування ";
			cin >> p[i].prog;
				break; 
			case INF:
				cout << " з чисельних методів ";
				cin >> p[i].chys_metody;
				break;
			default: 
				cout << "з педагогіки ";
				cin >> p[i].pedagogika;
				break;
			}
		}
	}
void Print(Student* p, const int N)
{
	string specStr[] = { "КН", "Інформатика", "МЕ", "ФІ", "ТН" };

	cout << string(111, '=') << endl;
	cout << "| № | Прізвище        | Курс | Спеціальність | Фізика | Математика | Програмування | Чис. методи | Педагогіка |" << endl;
	cout << string(111, '-') << endl;

	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(15) << left << p[i].prizv << " ";
		cout << "| " << setw(4) << right << p[i].kurs << " ";
		cout << "| " << setw(13) << left << specStr[p[i].spec] << " ";
		cout << "| " << setw(6) << right << p[i].fizyka << " ";
		cout << "| " << setw(10) << right << p[i].matematika << " ";

		switch (p[i].spec) {
		case KN:
			cout << "| " << setw(13) << right << p[i].prog << " "
				<< "| " << setw(11) << "" << " "
				<< "| " << setw(10) << "" << " |" << endl;
			break;
		case INF:
			cout << "| " << setw(13) << "" << " "
				<< "| " << setw(11) << right << p[i].chys_metody << " "
				<< "| " << setw(10) << "" << " |" << endl;
			break;
		default:
			cout << "| " << setw(13) << "" << " "
				<< "| " << setw(11) << "" << " "
				<< "| " << setw(10) << right << p[i].pedagogika << " |" << endl;
			break;
		}
	}
	cout << string(111, '=') << endl;
}


void CountSatisfactory(Student* p, const int N, int& fizyka, int& matematika, int& prog, int& chys_metody, int& pedagogika) {
	fizyka = 0;
	matematika = 0;
	prog = 0;
	chys_metody = 0;
	pedagogika = 0;
	for (int i = 0;i < N ;i++) {
		if ( p[i].matematika == 3) {
			matematika++;

		}
		if (p[i].fizyka == 3) {
			fizyka++;
		}
		switch (p[i].spec) {
		case KN: if (p[i].prog == 3) prog++; break;
		
		case INF:if (p[i].chys_metody == 3) chys_metody++; break;

		default:if (p[i].pedagogika == 3) pedagogika++; break;
			
		}
	}
}

void PrintGoodStudents(Student* p, const int N) {
	for (int i = 0; i < N; i++) {
		if (((p[i].matematika == 4) || (p[i].matematika == 5)) &&
			((p[i].fizyka == 4) || (p[i].fizyka == 5))) {
			cout << "прізвище студента " << p[i].prizv << endl;
		}
	}
}











int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "кількість студентів ";
	cin >> N;
	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	int fizyka;
	int matematika;
	int prog;
	int chys_metody;
	int pedagogika;
	CountSatisfactory(p, N, fizyka, matematika, prog, chys_metody, pedagogika);
	cout << "\nКількість оцінок «задовільно» (3) з кожного предмета:" << endl;
	cout << "Фізика: " << fizyka << endl;
	cout << "Математика: " << matematika << endl;
	cout << "Програмування: " << prog << endl;
	cout << "Чисельні методи: " << chys_metody << endl;
	cout << "Педагогіка: " << pedagogika << endl;

	cout << "\nСтуденти з оцінками 4 або 5 з фізики та математики:" << endl;
	PrintGoodStudents(p, N);
	delete[]p;
	return 0;
}
	


