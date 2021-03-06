#include <iostream>
#include <cstdio>

unsigned long long  _mergeSort(int arr[], int temp[], int left, int right);
unsigned long long merge(int arr[], int temp[], int left, int mid, int right);

 long long mergeSort(int arr[], int array_size)
{
    int* temp = new int[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

unsigned long long _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid;
  unsigned long long inv_count = 0;
  if (right > left)
  {

    mid = (right + left)/2;

    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);

    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

unsigned long long merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  unsigned long long inv_count = 0;

  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];

      inv_count = inv_count + (mid - i);
    }
  }

  while (i <= mid - 1)
    temp[k++] = arr[i++];

  while (j <= right)
    temp[k++] = arr[j++];

  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}


int main(int argv, char** args)
{

  int n, i;
  int* arr = new int[1000020];

  scanf("%d\n", &n);
  for(i = 0; i < n; i++)
     scanf("%d", &arr[i]);
  printf("%llu", mergeSort(arr, n));
  return 0;
}