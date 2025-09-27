#include <iostream>
using namespace std;

int recSum(int *arr[], int sizes[], int dim, int sm)
{
    if (dim == -1)
    {
        return sm;
    }
    for (int i = 0; i < sizes[dim]; i++)
    {
        sm += arr[dim][i];
    }
    return recSum(arr, sizes, dim - 1, sm);
}

int main()
{
    int dim = 3;
    int sizes[] = {1, 2, 3};
    int **arr = new int *[dim];
    int cnt = 1;
    for (int i = 0; i < dim; i++)
    {
        arr[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; j++)
        {
            arr[i][j] = cnt++;
        }
    }

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "SUM: " << recSum(arr, sizes, dim - 1, 0) << endl;
}
