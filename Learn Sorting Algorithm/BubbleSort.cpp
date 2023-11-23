void bubbleSort(int arr[], int n)

{

    for (int i = n - 1; i >= 0; i--)
    {

        int did = 0;

        for (int j = 0; j < i; j++)
        {

            if (arr[j] > arr[j + 1])
            {

                int temp = arr[j + 1];

                arr[j + 1] = arr[j];

                arr[j] = temp;

                did = 1;
            }
        }

        if (did == 0)
        {

            break;
        }
    }
}