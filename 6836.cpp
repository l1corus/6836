#include <iostream>
#include <vector>

using namespace std;

// вычисляем сумму цифр
int sum_digits(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main()
{
    // a = true => первое число, делящееся на 2023 найдено
    bool a = false;
    int max_sum = 0;
    vector<int> numbers_with_max_sum_digits[10];

    for (int i = 2000000000; i > 1000000001; i--)
    {
        if (i % 2023 == 0 and i % 10 == 1)
        {
            a = true;
            cout << i << "\t" << i / 2023 << "\n";


            // если у числа сумма цифр больше, чем максимальная на данный момент
            int sum_digits_i = sum_digits(i);
            if (sum_digits_i > max_sum) {
                max_sum = sum_digits_i; 
                numbers_with_max_sum_digits->clear();
                numbers_with_max_sum_digits->push_back(i);
            }
            else
            {
                // если у числа сумма цифр равна максимальной
                if (sum_digits_i == max_sum)
                {
                    numbers_with_max_sum_digits->push_back(i);
                }
            }
        }

        if (a) i -= 2022;
    }
    for (int i = 0; i < numbers_with_max_sum_digits->size(); i++)
    {
        cout << numbers_with_max_sum_digits->at(i) << "\t sum_digits = " << max_sum << endl;
    }
}
