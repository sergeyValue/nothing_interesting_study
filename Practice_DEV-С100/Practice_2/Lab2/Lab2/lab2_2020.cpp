/*************************************************************
	Практическое занятие №2. 
	
	Инструкции (условная, выбор, циклы)
	Логические операторы, тернарный (условный) оператор 
	Побитовые операторы.
							
*************************************************************/

#include <iostream>


#define	  stop __asm nop	//с помощью директивы препроцессора задаем макроподстановку
/***************************************************************/
int main()
{
	setlocale(LC_ALL, "Ru");
// ********************************************************
	//Задание 1. Условная инструкция if-else.Переключатель switch 

	//Задание 1.1 Напишите фрагмент кода, который переводит код символа, 
	//хранящийся в переменной ch в противоположный регистр.
	//Требуется предусмотреть проверку ситуации, когда пользователь ввел цифру
	//или нажал другую клавишу, которой символ не соответствует

	//Подсказка: работаем только с символами английского алфавита, для которого в таблице
	// кодов ASCII код каждой буквы нижнего регистра на 0x20 больше кода   // это на 32 !
	// соответствующей буквы верхнего регистра.
	
	//Обратите внимание, что в кодировочной таблице между буквами верхнего и нижнего регистра 
        //расположены некоторые иные символы
		// там расположены:  [ \ ] ^ _ `
	{
		// Программа меняет букву с большой на маленькую и наоборот (только английские символы)
		char ch;
		std::cout << "Введите символ английского алфавита: " << std::endl;
		std::cin >> ch;
		if ((ch >= 'A') && (ch <= 'Z'))
		{
			// меняем регистр
			ch += 32;
			std::cout << ch << std::endl;
		}
		else if ((ch >= 'a') && (ch <= 'z'))
		{
			ch -= 32;
			std::cout << ch << std::endl;
		}
		else {
			std::cout << "Error!!!!";
		}

		stop
	}
	//Задание 1.2 Напишите фрагмент кода, который реализует с помощью if (if/else)
	//следующую логику: 
	//если x меньше или равен 0, y=0
	//если x больше 0 но меньше 1, то y=x,
	//если x больше или равен 1, то y=1
	//Подумайте: какого типа должны или могут быть x и y?
	{
		// могут быть типа int и char
		int x;
		int y;
		if (x <= 0) 
		{
			y = 0;
		}
		else if (x >= 1) 
		{
			y = 1;
		}
		else {
			y = x;
		}

	stop
	}
	//Задание 1.3 Напишите фрагмент кода, который реализует с помощью switch
	//следующую логику: 
	//в переменной cInput типа char дано значение символа,введенного любым способом.
	//Если введен символ 'y' (т.е. yes) в любом регистре, то присвоить
	//переменной у значение переменной x
	//Если введен символ 'n' (т.е. no) в любом регистре, то присвоить
	//переменной у значение (x * 2)
	//Если любой другой симол, то вывести сообщение об ошибке
	{
		char ch;
		//сформировали значение
		int x = 5;
		int y = 6;

		std::cout << "..." << std::endl;
		std::cin >> ch;

		//switch
		switch (ch)
		{
		case 'y': 
		case 'Y':
			y = x;
			break;
		case 'n': 
		case 'N':
			y = x * 2;
			break;
		default:
			std::cout << "Error!" << std::endl;
			break;
		}
	stop
	}
// ********************************************************?????????????????????????????????????????????????
	//Задание 2. Логические операторы.
	// В Григорианском календаре (которым мы все пользуемся) високосный год
	// определяется по следующему алгоритму: високосным является каждый четвертый год,
	// но каждый сотый високосным НЕ является, при этом каждый 400-й год все таки 
	// високосный. Т.е. 1823 - не високосный, 1824 - високосный, 1900 - не високосный,
	// 2000 - високосный.
	// Напишите фрагмент кода, такой что:
	// логическая переменная isLeapYear принимает значение true, если год, заданный
	// переменной year - високосный.

	// Примечание: НЕ надо пользоваться инструкциями if-else, switch и тернарным оператором 
	//             НАДО написать логическое выражение в одну строку.
	//(*)если возникнут затруднения при решении задачи, то можно сначала решить ее с помощью if-else,
	// а потом уже выполнить предложенное задание.
	{
		int year = 1823;	// не высокосный
		//int year = 1824;	// высокосный
		//int year = 1900;	// не высокосный
		//int year = 2000; 	// высокосный

		//Вычислили значение 
		bool isLeapYear = (year % 4 == 0) || (!(year % 100 == 0) && (year % 400 == 0));

		std::cout.setf(std::ios::boolalpha);  // для вывода вида true/false
		std::cout << isLeapYear << std::endl;

		stop
	}


// *******************************************************
	//Задание 3. Тернарный оператор.  
	//С помощью тернарного оператора найдите максимальное из трех значений

	//(*)если возникнут затруднения при решении задачи, то можно сначала решить ее с помощью if-else,
	// а потом уже выполнить предложенное задание.
	{
		int x = 4;
		int y = 5;
		int z = 2;
		int max;
		max = (x >= y && x >= z) ? x : (y >= z) ? y : z;
	stop	
	}

// ********************************************************
	//Задание 4. Циклы.

	//Задание 4.1 Напишите фрагмент кода, который реализует с помощью for
	//следующую логику: найти сумму заданного диапазона целых чисел.
	//Задайте границы с помощью потока ввода (или прямо в коде).
	//Предусмотрите защиту от ввода нижней границы больше, чем верхней.
	{
		int high;
		int low;
		int sum = 0;
		
		
		for (;;)	// бесконечный цикл для программы
		{
			std::cout << "Введите нижную и верхнюю границу диапазона: " << std::endl;
			//1) сформировать границы диапазона
 			std::cin >> low >> high;
			//2) проверить корректность значений
			if (low < high)
			{
				//3) вычислить сумму
				for (int i = low; i <= high; i++)
				{
					sum += i;
				}
				//4) проверить в отладчике значение (или вывести на консоль)
				std::cout << "Сумма = " << sum;
				break;	// выход из цикла
			}
			else {
				std::cout << "Нижняя граница больше, чем верхняя!" << std::endl;
				continue;
			}
		}
		
	stop
	}


	//Задание 4.2 Напишите фрагмент кода, который реализует с помощью do-while
	//следующую логику: на каждой итерации цикла ввести с консоли целое значение
	// и покинуть цикл, если значение удовлетворяет условию: 
	// значение больше или равно 10 и четное.

	//Замечание: проверка на четность с использованием операции остатка от деления
	//нацело генерирует очень неэффективный код. Попробуйте реализовать альтернативный
	//вариант.

	{
		int value;
		std::cout << "Введите значение больше 10 и четное: " << std::endl;
		do
		{
			std::cin >> value;
			std::cout << value << std::endl;
		} while (!((value >= 10) && (!(value & 1) == 1)));		// если например value = 2 // ....0010 & ....0001 = ....0000 (0)
		//(value & 1) == 0 - чётное
		//(value & 1) == 1 - нечётное

	stop
	}

	//Задание 4.3 Напишите фрагмент кода, который реализует с помощью while
	//следующую логику: исходно int x = 0; 
	//на каждой итерации x=x+1, sum=sum+1/x
	//найти значение x, при котором sum>1.7
	{
		// не понял задачу
		int x = 0;				
		double sum = 0;

		while (!(sum > 1.7))
		{
			std::cin >> x;
			x += 1;
			sum += (1 / static_cast<double>(x));
		}
	stop
	}
// ********************************************************
//Задание 5 Побитовая арифметика (and, or, xor, not), сдвиги.
	//5.1 
	{
	//а)Задайте значение пременной типа char с помощью потока ввода.
	//(для отладки можно задать значение с помощью числового литерала в 2-чном или 16-ричном коде)

	char val= 0011'0000;    		// (48 / 0х30)
	unsigned char mask;

	//б)	обнулите значение его 6-го бита
	val = val & 0b0001'0000;		// 0010'0000    // 0х10  / 16
	//mask = ~(1 << 4);
	//val = val & mask;
	stop
			
	//в)	определите значение его 5го бита
	mask = 1 << 4;				// 0001'0000
	bool res = val & mask;			// 1 - true / 0 - false  // если там ноль то установится 0, если 1 установится 1
	stop
	//г)	установите в 1 бит на 4-ой позиции  
	//  val = val | 0b0000'1000;
	mask = 1 << 3;				// 0000'1000
	val = val | mask;			// при val = 00010000(0х10)  - 0х18  (24) / 00010010 
	stop
	}

	//5.2 
	{
	//Если число кодируется более чем одним байтом, то важно, 
	//в каком порядке байты записываются в памяти компьютера или передаются по линиям связи.	//В архитектуре x86  используется порядок от младшего к старшему (англ. little-endian)
	//Для протоколов TCP/IP стандартным является порядок от старшего к младшему (англ. big-endian)  
	//Задайте значение x, например:

	int x = 0xA1B2C3D4;
	//байты числа в памяти следуют в порядке от младшего к старшему
	//поменяйте местами байты так, чтобы они следовали в памяти в обратном порядке 
	//(от старшего к младшему)
	//Например, если x= 0xA1B2C3D4, то после перестановки получим 0xD4C3B2A1

	//обмен байт безопасно выполнять только для беззнаковых типов
	x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;
	x = (x & 0x0000FFFF) << 16 | (x & 0xFFFF0000) >> 16;	// 0xD4C3B2A1

	std::cout << std::hex << x;
	stop
	}
// ********************************************************
	//Задание 6 Побитовая арифметика (and, or, xor, not), сдвиги.
	//6.1 
	{
		//Задайте значение y, например, с помощью потока ввода 
		//или с помощью числового литерала в двоичном или 16-ричном виде

		//С помощью побитовых операторов и операторов сдвига:
		//выведите значение "y"  на консоль в двоичном виде, например:
		// если y==9, то 
		// 0 0 0 0 ...   0 0 1 0 0 1 (количество двоичных цифр зависит от платформы)

		unsigned int y = 9;			// 000000000000000000000000000001001
		unsigned int mask;
		int shiftBit = 31;

		for (int i = 0; i <= 31; i++) {
			mask = 1 << shiftBit;		// 100000000000000000000000000000000
			if ((y & mask) == mask)
			{
				std::cout << "1";
				mask = 1 << shiftBit;
			}
			else {
				std::cout << "0";
				mask = 1 << shiftBit;
			}
			shiftBit--;
		}
		
	}
	//6.2
	{
		//Выведите значение "y"  на консоль в двоичном виде, 
		//пропустив незначащие нули, например:
		// если y==9, то результат  1 0 0 1
		unsigned int y = 9;				// 000000000000000000000000000001001
		unsigned int mask;
		int shiftBit = 31;
		bool foundedOne = false;			// тригер. при первом нахождении еденицы включается

		for (int i = 0; i <= 31; i++) {
			mask = 1 << shiftBit;			// 100000000000000000000000000000000

			if ((y & mask) == mask)
			{
				std::cout << "1";
				mask = 1 << shiftBit;
				foundedOne = true;
			}
			else {
				// при первой встречной единице начинает печатать дальше 0
				if (foundedOne) {		
					std::cout << "0";
				}
				mask = 1 << shiftBit;
			}
			shiftBit--;
		}

	}
	//6.3 (*)
	{
		//Дана целая переменная
		//Задайте значение y, например, с помощью потока ввода

	//"Сдвиньте" все единицы в этой переменной вправо, например:
	//было:   0100 1111 0000 0000 0110 1111 0000 0010
	//стало:  0000 0000 0000 0000 0000 1111 1111 1111
	//Выведите на консоль полученное значение в двоичном виде ( можно на печати не разделять тетрады пробелом)

		int y = 9;					// 000000000000000000000000000001001
		unsigned int maskLeft = 0x80000000;		// 100000000000000000000000000000000
		unsigned int maskRight = 0x01;			// 000000000000000000000000000000001

		while (maskLeft > maskRight)
		{
			if (y & maskLeft == 1)
			{
				if (y & maskRight == 0)
				{
					maskLeft &= 1;		// снимаем 1 в левом бите
					maskRight |= 1;		// устанавливаем 1 в правом бите
					maskLeft >>= 1;		// сдвигаем maskLeft на 1 вправо
					maskRight <<= 1;	// сдвигаем maskRight на 1 влево
					std::cout << "0";	// вывод результата
				}
				else {
					maskRight <<= 1;	// сдвигаем maskRight на 1 влево
				}
				std::cout << "1";		// вывод результата
			}
			else {
				maskLeft >>= 1;			// сдвигаем maskLeft на 1 вправо
				std::cout << "0";		// вывод результата
			}
		}


		stop
	}
	//6.4 (*)
	//Какие операции следует применить к заданному ниже операнду sNum для
	//того, чтобы переменная sRes приняла требуемое значение?
		
	//Замечание 1: значения подобраны таким образом, что в каждом случае достаточно
	//использовать один оператор (и при необходимости маску) 
	
	//Замечание 2: посредством оператора xor (подобрав соответствующую маску)
	//можно получить любое значение => этот оператор предполагается использовать
	//в том случае, когда все остальные уже "не спасают" 
	{
		// short  –32768 до 32767     2 байта
		short sNum = 0x8008;	// 1000'0000'0000'1000		(-32760)
		unsigned short mask;
		short sRes, sRes1, sRes2, sRes3, sRes4, sRes5;
		
		sRes = 0x7ff7;			// 0111'1111'1111'0111		(32759) 
		sRes = ~sRes;			// 1000'0000'0000'1000		(-32760)

		sRes1 = 0x8ff8;			// 1000'1111'1111'1000		(-28680)
		sRes1 = sNum & sRes1;		// 1000'0000'0000'1000		(-32760)

		sRes2 = 0x0008;			// 0000'0000'0000'1000		(8)
		sRes2 = sRes2 | sNum;		// 1000'0000'0000'1000		(-32760)

		sRes3 = 0x7f08;			// 0111'1111'0000'1000		(32520)
		sRes3 = sRes3 << 12;		// 1000'0000'0000'0000
		mask = 1 << 3;			// 0000'0000'0000'1000
		sRes3 = sRes3 | mask;		// 1000'0000'0000'1000		(-32760)

		sRes4 = 0xf001;			// 1111'0000'0000'0001		(-4095)
		sRes4 = sRes4 << 3;		// 1000'0000'0000'1000		(-32760)

		sRes5 = 0x0010;			// 0000'0000'0001'0000		(16)
		sRes5 = sRes5  << 11;
		mask = 1 << 3;;			// 1000'0000'0000'0000
		sRes5 = sRes5 | mask;		// 1000'0000'0000'1000		(-32760)
		stop
	}


	return 0;//код завершения приложения
}	// Конец функции main()
