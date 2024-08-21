#include <iostream>

//Задача №6
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int* removePrimes(int* arr, int size, int& newSize) {
    int* newArr = new int[size]; // Максимальный размер
    newSize = 0;

    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newArr[newSize++] = arr[i];
        }
    }

    return newArr;
}

//Задача №7
void distributeElements(int* arr, int size, int** positives, int& posCount, int** negatives, int& negCount, int** zeros, int& zeroCount) {
    posCount = 0;
    negCount = 0;
    zeroCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            (*positives)[posCount++] = arr[i];
        }
        else if (arr[i] < 0) {
            (*negatives)[negCount++] = arr[i];
        }
        else {
            (*zeros)[zeroCount++] = arr[i];
        }
    }
}


int main()
{
    setlocale(LC_ALL, "rus");
    {
    /*
        Задание 1:
        Даны два массива : А[M] и B[N](M и N вводятся с клавиатуры).
        Необходимо создать третий массив минимально возможного размера, 
        в котором нужно собрать элементы массива A, которыене включаются 
        в массив B, без повторений.
        */
        int M, N;

        std::cout << "Введите размер массива A: ";
        std::cin >> M;
        int* A = new int[M];
        std::cout << "Введите элементы массива A: ";
        for (int i = 0; i < M; i++) {
            std::cin >> A[i];
        }

        std::cout << "Введите размер массива B: ";
        std::cin >> N;
        int* B = new int[N];
        std::cout << "Введите элементы массива B: ";
        for (int i = 0; i < N; i++) {
            std::cin >> B[i];
        }

        int* result = new int[M]; // Максимальный возможный размер
        int count = 0;
        for (int i = 0; i < M; i++) {
            bool found = false;
            for (int j = 0; j < N; j++) {
                if (A[i] == B[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                bool alreadyExists = false;
                for (int k = 0; k < count; k++) {
                    if (result[k] == A[i]) {
                        alreadyExists = true;
                        break;
                    }
                }
                if (!alreadyExists) {
                    result[count++] = A[i];
                }
            }
        }

        std::cout << "Элементы массива A, которые не входят в B: ";
        for (int i = 0; i < count; i++) {
            std::cout << result[i] << " ";
        }

        delete[] A;
        delete[] B;
        delete[] result;
    }

    {
        /*
            Задание 2: 
    Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). 
    Необходимо создать третий массив минимально возможного размера, 
    в котором нужно собрать элементы массивов A и B, 
    которые не являются общими для них, без повторений.
        */
        int M, N;

        std::cout << "Введите размер массива A: ";
        std::cin >> M;
        int* A = new int[M];
        std::cout << "Введите элементы массива A: ";
        for (int i = 0; i < M; i++) {
            std::cin >> A[i];
        }

        std::cout << "Введите размер массива B: ";
        std::cin >> N;
        int* B = new int[N];
        std::cout << "Введите элементы массива B: ";
        for (int i = 0; i < N; i++) {
            std::cin >> B[i];
        }
        int* result = new int[M + N]; // Максимальный возможный размер
        int count = 0;

        for (int i = 0; i < M; i++) {
            bool found = false;
            for (int j = 0; j < N; j++) {
                if (A[i] == B[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result[count++] = A[i];
            }
        }

        for (int i = 0; i < N; i++) {
            bool found = false;
            for (int j = 0; j < M; j++) {
                if (B[i] == A[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result[count++] = B[i];
            }
        }

        // Удаляем повторы
        int* finalResult = new int[count];
        int finalCount = 0;
        for (int i = 0; i < count; i++) {
            bool exists = false;
            for (int j = 0; j < finalCount; j++) {
                if (finalResult[j] == result[i]) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                finalResult[finalCount++] = result[i];
            }
        }

        std::cout << "Элементы, не являющиеся общими: ";
        for (int i = 0; i < finalCount; i++) {
            std::cout << finalResult[i] << " ";
        }

        delete[] A;
        delete[] B;
        delete[] result;
        delete[] finalResult;
    }

    {
        /*
        Задание 3:
Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). 
Необходимо создать третий массив минимально возможного рамзера, 
в котором нужно собрать элементы обоих массивов.        
        */
        int M, N;

        std::cout << "Введите размер массива A: ";
        std::cin >> M;
        int* A = new int[M];
        std::cout << "Введите элементы массива A: ";
        for (int i = 0; i < M; i++) {
            std::cin >> A[i];
        }

        std::cout << "Введите размер массива B: ";
        std::cin >> N;
        int* B = new int[N];
        std::cout << "Введите элементы массива B: ";
        for (int i = 0; i < N; i++) {
            std::cin >> B[i];
        }
        int* result = new int[M + N];
        int count = 0;

        for (int i = 0; i < M; i++) {
            result[count++] = A[i];
        }

        for (int i = 0; i < N; i++) {
            bool exists = false;
            for (int j = 0; j < M; j++) {
                if (B[i] == A[j]) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                result[count++] = B[i];
            }
        }

        std::cout << "Объединенный массив: ";
        for (int i = 0; i < count; i++) {
            std::cout << result[i] << " ";
        }

        delete[] A;
        delete[] B;
        delete[] result;
    }

    {
        /*
        Задание 4:
Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий
массив минимально возможного рамзера, в котором нужно собрать общие элементы двух
массивов без повторений        
        */
        int M, N;

        std::cout << "Введите размер массива A: ";
        std::cin >> M;
        int* A = new int[M];
        std::cout << "Введите элементы массива A: ";
        for (int i = 0; i < M; i++) {
            std::cin >> A[i];
        }

        std::cout << "Введите размер массива B: ";
        std::cin >> N;
        int* B = new int[N];
        std::cout << "Введите элементы массива B: ";
        for (int i = 0; i < N; i++) {
            std::cin >> B[i];
        }
        int* result = new int[M < N ? M : N]; // Максимальный возможный размер
        int count = 0;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i] == B[j]) {
                    bool exists = false;
                    for (int k = 0; k < count; k++) {
                        if (result[k] == A[i]) {
                            exists = true;
                            break;
                        }
                    }
                    if (!exists) {
                        result[count++] = A[i];
                    }
                    break;
                }
            }
        }

        std::cout << "Общие элементы: ";
        for (int i = 0; i < count; i++) {
            std::cout << result[i] << " ";
        }

        delete[] A;
        delete[] B;
        delete[] result;
    }

    {
        /*
        Задание 5:
Дан массив: А[M] (M вводи тся с клавиатуры). Необходимо удалить из массива четные или
нечетные значения. Пользователь вводит данные в массив, а также с помощью меню решает, 
что нужно удалить.
        */
        int M;
        std::cout << "Введите размер массива A: ";
        std::cin >> M;
        int* A = new int[M];

        std::cout << "Введите элементы массива A: ";
        for (int i = 0; i < M; i++) {
            std::cin >> A[i];
        }

        int choice;
        std::cout << "Введите 1, чтобы удалить четные числа, 2 - нечетные: ";
        std::cin >> choice;

        int* result = new int[M]; // Максимальный размер
        int count = 0;
        for (int i = 0; i < M; i++) {
            if ((choice == 1 && A[i] % 2 != 0) || (choice == 2 && A[i] % 2 == 0)) {
                result[count++] = A[i];
            }
        }

        std::cout << "Результирующий массив: ";
        for (int i = 0; i < count; i++) {
            std::cout << result[i] << " ";
        }

        delete[] A;
        delete[] result;
    }

    {
        /*
        Задание 6:
Написать функцию, которая получает указатель на динамический массив и его размер. Функция
должна удалить из массива все простые числа и вернуть указатель на новый динамический
массив.
        */
        int size;
        std::cout << "Введите размер массива: ";
        std::cin >> size;
        int* A = new int[size];

        std::cout << "Введите элементы массива: ";
        for (int i = 0; i < size; i++) {
            std::cin >> A[i];
        }

        int newSize;
        int* result = removePrimes(A, size, newSize);

        std::cout << "Массив без простых чисел: ";
        for (int i = 0; i < newSize; i++) {
            std::cout << result[i] << " ";
        }

        delete[] A;
        delete[] result;
    }

    {
        /*
            Задание 7:
Написать функцию, которая получает указатель на статический массив и его размер. Функция
распределяет положительные, отрицательные и нулевые элементы в отдельные динамические
массивы.
        */
        int size;
        std::cout << "Введите размер массива: ";
        std::cin >> size;
        int* arr = new int[size];

        std::cout << "Введите элементы массива: ";
        for (int i = 0; i < size; i++) {
            std::cin >> arr[i];
        }

        int* positives = new int[size]; // Максимально возможный размер
        int* negatives = new int[size];
        int* zeros = new int[size];
        int posCount, negCount, zeroCount;

        distributeElements(arr, size, &positives, posCount, &negatives, negCount, &zeros, zeroCount);

        std::cout << "Положительные: ";
        for (int i = 0; i < posCount; i++) {
            std::cout << positives[i] << " ";
        }

        std::cout << "\nОтрицательные: ";
        for (int i = 0; i < negCount; i++) {
            std::cout << negatives[i] << " ";
        }
        std::cout << "\nНули: ";
        for (int i = 0; i < zeroCount; i++) {
            std::cout << zeros[i] << " ";
        }

        delete[] arr;
        delete[] positives;
        delete[] negatives;
        delete[] zeros;
    }
    
    return 0;
}

