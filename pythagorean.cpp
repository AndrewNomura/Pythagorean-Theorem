#include <iostream>
#include <vector>
using namespace std;

struct Node {
	Node() :next(NULL), elem(0) {}

	friend ostream& operator<<(ostream& os, const Node& n) {
		return os << n.elem;
	}

	friend istream& operator>>(istream& is, Node& n) {
		return is >> n.elem;
	}

	Node* next;
	int elem;
};

class SLinkedList {
public:
	SLinkedList() :head(NULL), size_(0) {}

	bool empty() const { return size_ == 0; }
	size_t size() const { return size_; }

	friend ostream& operator<<(ostream& os, const SLinkedList& sll) {
		if (sll.empty()) { return os << "empty list...\n"; }
		Node* p = sll.head;
		while (p->next != NULL) {
			os << *p << " ";
			p = p->next;
		}
		return os;
	}
	friend istream& operator>>(istream& is, SLinkedList& sll) {
		return is >> sll;
	}

	void addToEndOfList(const int& data) {
		Node* newNode = new Node;
		Node* p = head;
		newNode->elem = data;
		if (size_ == 0) {
			head = newNode;
		}
		else {
			while (p->next != NULL) {
				p = p->next;
			}
			p->next = newNode;
		}
		size_++;
	}


	int* pythagorean() {
		int arr[10] = {}, i = 0;
		static int ans[10];
		Node* p = head;

		while (p->elem != -1) {
			arr[i] = p->elem;
			p = p->next;
			i++;
		}

		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
			for (int j = i + 1; j < sizeof(arr) / sizeof(arr[0]); j++) {
				for (int k = j + 1; k < sizeof(arr) / sizeof(arr[0]); k++) {
					int a = arr[i] * arr[i], b = arr[j] * arr[j], c = arr[k] * arr[k];
					if (a == b + c || b == a + c || c == a + b) {
						ans[0] = arr[i], ans[1] = arr[j], ans[2] = arr[k];
						return ans;
						break;
					}
				}
			}
		}
		return arr;
		
	}

	

private:
	Node* head;
	size_t size_;
};


int main() {
	int input = 0;
	SLinkedList s;
	cout << "Welcome to Pythagorean Theorem" << endl << endl;
	cout << "Enter your list of numbers: (-1 to finish input) ";
	do {
		cin >> input;
		s.addToEndOfList(input);
	} while (input != -1);


	cout << s << endl;

	int* p = s.pythagorean();

	for (int i = 0; i < 3; i++) {
		cout << *(p + i) << " ";
	}
	

	return 0;
}
