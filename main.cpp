#include "Test.h"
#include <iostream>
using namespace std;

vector<int> check_branch_integrity(vector<int> min_heap, unsigned int changed_index)
{
  while(changed_index < min_heap.size())
  {
    unsigned int left = (changed_index * 2) + 1;
    unsigned int right = (changed_index * 2) + 2;
    int current = min_heap[changed_index];
    unsigned int parent_index = changed_index % 2 == 0 ? (changed_index - 2) / 2 : (changed_index - 1) / 2;
    if(left < min_heap.size() && left >= 0 && current > min_heap[left])
    {
      min_heap[changed_index] = min_heap[left];//200 to 30
      min_heap[left] = current;//30 to 200
      changed_index = left;
    }else if(right < min_heap.size() && right >= 0 && current > min_heap[right])
    {
      min_heap[changed_index] = min_heap[right];
      min_heap[right] = current;
      changed_index = right;
    } else if(parent_index < min_heap.size() && parent_index >= 0 && current < min_heap[parent_index])
    {
      min_heap[changed_index] = min_heap[parent_index];
      min_heap[parent_index] = current;
      changed_index = parent_index;
    }
    else
    {
      break;
    }
  }

  return min_heap;
}

vector<int> replace(vector<int> min_heap, int replaced_value, int replacement)
{
    unsigned int changed_index = -1;
    for(unsigned int i = 0; i < min_heap.size(); ++i)
    {
      if(min_heap[i] == replaced_value)
      {
        changed_index = i;
        min_heap[i] = replacement;
        break;
      }
    }
    // min_heap = check_branch_integrity(min_heap, changed_index);

    return check_branch_integrity(min_heap, changed_index);
}

int main ()
{
    test();
    return 0;
}
