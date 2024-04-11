#include <iostream>
#include <stdexcept>

template <typename T>
struct Node
{
    T data;
    Node* next;

    Node(const T& x) : data(x), next(nullptr) {} //Node Construction method, assigns null to the next pointer
};

template <typename T>
class LinkedList
{
private:
    Node<T>* list; //Creates a ptr that points to the first element of the list

public:
    //Constructor
    LinkedList() : list(nullptr) {} //starts the list with 0 elements, hence null

    //Checks if List is Empty
    bool listIsEmpty() const
    {
        return(list == nullptr); //If list points to null then the list is empty
    }

    //Print List
    std::string toString() const
    {
        std::string str = "(";
        Node<T>* aux;
        aux = list; //Creates an auxiliar node that traverses the list
        while (aux != nullptr)
        {
            // Convert the data to string and concatenate
            str += std::to_string(aux->data) + ", ";
            aux = aux->next;
        }
        str = str +")" + std::endl;

        // Append closing parenthesis and newline character
        str += ")" + "\n";

        return str;
    }

    //Insert a node at the beginning of the list
    void addStart(T x)
    {
        Node<T>* p = new Node<T>(x); //Uses Node constructor to create the node that will be inserted
        p->next = list;
        list = p;
    }

    //Insert a node at the end of the list
    void addEnd(T x)
    {
        Node<T>* p = new Node<T>(x); //Uses Node constructor to create the node that will be inserted
        if (listIsEmpty()) //if the list is empty it assigns it directly to the start/end
        {
            list = p;
        }
        else
        {
            Node* aux = list; //creates an aux ptr that points to the first element
            while (aux->next != nullptr) //searches for the end of the list
            {
                aux = aux->next; 
            }
            aux->next = p; //when the end is reached, it creates a connection between the last node and the new node
        }

    }
    T removeLast() {
        if (listIsEmpty()) {
            return NULL;
        }

        T w = NULL;
        Node<T>* aux = list;
        //searches for the last node
        while (aux->next->next != nullptr) 
        {
            aux = aux->next;
        }
        //Assigns the data from the last node to w
        w = aux->next->data;
        delete aux->next; //deletes the node
        aux->next = nullptr; //aasigns null to the node behind

        return w;
    }

    //Delete Node at the start
    T removeFirst()
    {
        if (listIsEmpty()) {
            return NULL;
        }

        T w = NULL;
        Node<T>* aux = list;
        w = list->data; //assigns the data from the eliminated Node to w
        lista = list->next; //Connects list to the second Node
        delete aux; //returns memory
        return w;
    }

    //Search a Node
    int search(T element)
    {
        if (list == nullptr) return -1;

        int index = 0;
        Node<T>* aux = list;
        while (aux != nullptr)
        {
            if (element == aux->data) return index;
            index++;
            aux = aux->next;
        }
        return -1;
    }
    
    //Insert between two nodes
    //Delete bewteen two nodes

    void menu()
    {
        std::cout << "Elija una opción" << std::endl;
        std::cout << "1. Agregar elemento al inicio" << std::endl;
        std::cout << "2. Agregar elemento al final" << std::endl;
        std::cout << "3. Eliminar elemento al inicio" << std::endl;
        std::cout << "4. Eliminar elemento al final" << std::endl;
        std::cout << "5. Recuperar un elemento" << std::endl;
        std::cout << "6. Fin del programa" << std::endl;
    }

};

int main()
{
    ListaLigada lista;
    int option;
    float elemento;

    do
    {
        std::cout << "Escriba una opción" << std::endl;
        lista.menu();
        std::cin >> option;
        switch (option)
        {
        case 1:
            std::cout << "Ingrese el elemento a agregar al inicio: ";
            std::cin >> elemento;
            lista.insertarIni(elemento);
            break;
        case 2:
            std::cout << "Ingrese el elemento a agregar al final: ";
            std::cin >> elemento;
            lista.insertarFin(elemento);
            break;
        case 3:
            lista.suprimirIni();
            break;
        case 4:
            ista.suprimirFin();
            break;
        case 5:
            float r;
            std::cout << "Ingrese el elemento que desea recuperar: ";
            std::cin >> r;
            int pos = lista.getElement(r);
            if (pos != -1)
                std::cout << "El elemento se encuentra en la posicion " << pos << std::endl;
            break;
        case 6:
            std::cout << "Fin del programa. ";
            break;
        default:
            std::cout << "Opcion invalida";
            break;
        }
    }(option != 6);
    return 0;
}
