#include <iostream>

// Определение структуры узла списка
struct Node {
    int data;
    Node* next;
    
    // Конструктор для удобства создания узлов
    Node(int value) : data(value), next(nullptr) {}
};

// Класс для реализации связанного списка
class LinkedList {
private:
    Node* head;

public:
    // Конструктор для инициализации пустого списка
    LinkedList() : head(nullptr) {}

    // Метод для добавления нового элемента в конец списка
    void append(int value) {
        Node* newNode = new Node(value);
        
        // Если список пуст, новый узел становится его головой
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Иначе ищем конец списка и добавляем новый узел туда
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Метод для вывода элементов списка
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Деструктор для освобождения памяти после использования списка
    ~LinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    // Создание объекта связанного списка
    LinkedList myList;

    // Добавление элементов в список
    myList.append(5);
    myList.append(10);
    myList.append(15);

    // Вывод элементов списка
    std::cout << "Связанный список: ";
    myList.display();

    return 0;
}
