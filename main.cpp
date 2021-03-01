#include <iostream>
#include <deque>


using namespace std;

struct Document {
  int index;
  int priority;
};

int solution(deque<Document>& document_deque, int target_index) {
  int count = 0;
  int i = 0;
  while (true) {
    i++;
    if (i == document_deque.size()) {
      count++;
      if (document_deque.front().index == target_index) {
        return count;
      } else {
        document_deque.pop_front();
        i = 0;
      }
    }
    if (document_deque.front().priority < document_deque[i].priority) {
      document_deque.push_back(document_deque.front());
      document_deque.pop_front();
      i = 0;
    }
  }
}

int main() {
  int test_case;
  cin >> test_case;
  for (int i = 0; i < test_case; i++) {
    int document_deque_size, target_index;
    cin >> document_deque_size >> target_index;
    deque<Document> document_deque(document_deque_size);
    for (int j = 0; j < document_deque_size; j++) {
      int document_priority;
      cin >> document_priority;
      document_deque[j].index = j;
      document_deque[j].priority = document_priority;
    }
    cout << solution(document_deque, target_index) << endl;
  }
  return 0;
}