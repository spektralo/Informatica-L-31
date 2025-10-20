#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

// Valore per indicare l'infinito in alcune operazioni (se necessario)
#define INF len + 1

// Classe MGraph: rappresenta un grafo diretto utilizzando una matrice di adiacenza
template <class H>
class MatrixGraph {
private:
    int capacity;          // Numero massimo di nodi
    int nodeCount;         // Numero effettivo di nodi
    int edgeCount;         // Numero effettivo di archi
    int** adjacencyMatrix; // Matrice di adiacenza
    H** nodes;             // Array di puntatori ai nodi

    // Trova l'indice di un nodo dato il valore
    int findNodeIndex(H value) const {
        for (int i = 0; i < nodeCount; i++) {
            if (*nodes[i] == value) return i;
        }
        return -1; // Nodo non trovato
    }

public:
    // Costruttore
    MatrixGraph(int capacity) {
        this->capacity = capacity;
        nodeCount = 0;
        edgeCount = 0;

        // Inizializzazione della matrice di adiacenza
        adjacencyMatrix = new int*[capacity];
        for (int i = 0; i < capacity; i++) {
            adjacencyMatrix[i] = new int[capacity];
            for (int j = 0; j < capacity; j++) {
                adjacencyMatrix[i][j] = 0; // Nessun arco inizialmente
            }
        }

        // Inizializzazione della lista dei nodi
        nodes = new H*[capacity];
        for (int i = 0; i < capacity; i++) {
            nodes[i] = nullptr;
        }
    }

    // Distruttore
    ~MatrixGraph() {
        for (int i = 0; i < capacity; i++) {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;

        for (int i = 0; i < capacity; i++) {
            delete nodes[i];
        }
        delete[] nodes;
    }

    // Aggiunge un nodo al grafo
    MatrixGraph<H>* addNode(H value) {
        if (nodeCount == capacity) return this; // Capacità massima raggiunta
        if (findNodeIndex(value) >= 0) return this; // Nodo già presente

        nodes[nodeCount] = new H(value);
        nodeCount++;
        return this;
    }

    // Aggiunge un arco tra due nodi
    MatrixGraph<H>* addEdge(H from, H to) {
        int fromIndex = findNodeIndex(from);
        int toIndex = findNodeIndex(to);

        if (fromIndex < 0 || toIndex < 0) return this; // Nodo non trovato
        if (!adjacencyMatrix[fromIndex][toIndex]) { // Arco non presente
            adjacencyMatrix[fromIndex][toIndex] = 1;
            edgeCount++;
        }
        return this;
    }

    // Stampa il grafo
    void print() const {
        for (int i = 0; i < nodeCount; i++) {
            cout << "(" << i << ", " << *nodes[i] << ")" << " : ";
            for (int j = 0; j < nodeCount; j++) {
                if (adjacencyMatrix[i][j]) {
                    cout << *nodes[j] << " ";
                }
            }
            cout << endl;
        }
    }
};
