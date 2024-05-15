// CMSC 341 - Fall 2023 - Project 1
#include "csr.h"
///////////////CSR Class Implementation///////////////
CSR::CSR(){
    // set every member variable to its null value
    m_values = nullptr;
    m_col_index = nullptr;
    m_row_index = nullptr;
    m_nonzeros = 0;
    m_m = 0;
    m_n = 0;
    m_next = nullptr;
}


CSR::~CSR(){
    // deallocates the three member arrays
    if (m_values != nullptr) {
        delete[] m_values;
    }
    if (m_col_index != nullptr) {
        delete[] m_col_index;  
    }
    if (m_row_index != nullptr) {
        delete[] m_row_index;
    }
}


CSR::CSR(const CSR & rhs){
    // initializes member variables
    m_m = rhs.m_m;
    m_n = rhs.m_n;
    m_nonzeros = rhs.m_nonzeros;
    m_values = new int[m_nonzeros];
    m_col_index = new int[m_nonzeros];
    m_row_index = new int[m_m + 1];
    m_next = nullptr;

    // copies the arrays
    for (int i = 0; i < m_nonzeros; i++) {
        m_values[i] = rhs.m_values[i];
    }
    for (int i = 0; i < m_nonzeros; i++) {
        m_col_index[i] = rhs.m_col_index[i];
    }
    for (int i = 0; i <= m_m; i++) {
        m_row_index[i] = rhs.m_row_index[i];
    }
}


void CSR::clear(){
     // deallocates the three member arrays
    if (m_values != nullptr) {
        delete[] m_values;
    }
    if (m_col_index != nullptr) {
        delete[] m_col_index;
    }
    if (m_row_index != nullptr) {
        delete[] m_row_index;
    }
    // set every member variable to its null value
    m_values = nullptr;
    m_col_index = nullptr;
    m_row_index = nullptr;
    m_nonzeros = 0;
    m_m = 0;
    m_n = 0;
    m_next = nullptr;
}


bool CSR::empty() const{
    // checks if all member varaibles are in their null state
    if (m_nonzeros == 0 && m_m == 0 && m_n == 0 && m_values == nullptr && m_col_index == nullptr && m_row_index == nullptr) {
        return true; 
    } else {
        return false; 
    }
}


void CSR::compress(int m, int n, int array[], int arraySize){
    // clear in case there was still data
    clear();

    // initializes member variables
    m_m = m;
    m_n = n;
    m_nonzeros = 0;
    m_values = new int[arraySize];
    m_col_index = new int[arraySize];
    m_row_index = new int[m + 1];

    // populates the arrays
    for (int i = 0; i < m; i++) {
        // sets the row index
        m_row_index[i] = m_nonzeros;
        for (int j = 0; j < n; j++) {
            // captures the values for each row
            if (array[i * n + j] != 0) {
                m_values[m_nonzeros] = array[i * n + j];
                m_col_index[m_nonzeros] = j;
                m_nonzeros++;
            }
        }
    }

    // adds the last row index
    m_row_index[m] = m_nonzeros;
}


int CSR::getAt(int row, int  col) const{
    // checks if the range is valid
    if (row < 0 || col < 0 || col >= m_n || row >= m_m ) {
        throw std::runtime_error("Indices are not in valid range.");
    }
    
    // loop goes through however many populated items there are in each row
    for (int i = m_row_index[row]; i < m_row_index[row + 1]; i++) {
        if (m_col_index[i] == col) {
            return m_values[i];
        }
    }
    
    // if not found, just return 0 
    return 0;
} 


bool CSR::operator==(const CSR & rhs) const{
    // check if these member variables are all equal
    if (m_m != rhs.m_m || m_n != rhs.m_n || m_nonzeros != rhs.m_nonzeros) {
        return false;
    }

    // go through these two arrays to check if all the items are the same
    for (int i = 0; i < m_nonzeros; i++) {
        if (m_values[i] != rhs.m_values[i] || m_col_index[i] != rhs.m_col_index[i]) {
            return false;
        }
    }

    // check if the row array has the same values
    for (int i = 0; i <= m_m; i++) {
        if (m_row_index[i] != rhs.m_row_index[i]) {
            return false;
        }
    }

    return true;
}


int CSR::sparseRatio(){
    // find the percent of null entries in matrix 
    return (1 - (m_nonzeros/ (m_m * m_n))) * 100;
}


void CSR::dump(){
    cout << endl;
    if (!empty()){
        for (int i=0;i<m_nonzeros;i++)
            cout << m_values[i] << " ";
        cout << endl;
        for (int i=0;i<m_nonzeros;i++)
            cout << m_col_index[i] << " ";
        cout << endl;
        for (int i=0;i<m_m+1;i++)
            cout << m_row_index[i] << " ";
    }
    else
        cout << "The object is empty!";
    cout << endl;
}

//////////////CSRList Class Implementation///////////////
CSRList::CSRList(){
    // set member variables to null
    m_head = nullptr; 
    m_size = 0;
}


CSRList::CSRList(const CSRList & rhs){
    m_head = nullptr; 
    m_size = 0;
    CSR* curr = rhs.m_head;
    while (curr != nullptr) {
        // use the copy constructor of CSR
        CSR* newNode = new CSR(*curr);
        // insert a node at the beginning
        newNode->m_next = m_head;
        m_head = newNode;
        m_size++;
        curr = curr->m_next;
    }
}


CSRList::~CSRList(){
    // go through the linked list and delete everything
    while (m_head != nullptr) {
        CSR* curr = m_head;
        m_head = m_head->m_next;
        delete curr;
    }
}


bool CSRList::empty() const{
    if (m_head == nullptr && m_size == 0) {
        return true; 
    }
    return false; 
}


void CSRList::insertAtHead(const CSR & matrix){
    CSR* newNode = new CSR(matrix);
    newNode->m_next = m_head;
    m_head = newNode;
    m_size++;
}


void CSRList::clear(){
    // go through the linked list and delete everything
    while (m_head != nullptr) {
        CSR* curr = m_head;
        m_head = m_head->m_next;
        delete curr;
    }
    m_size = 0;
}


int CSRList::getAt(int CSRIndex, int row, int col) const{
    // check if the index matches with the size of the linked list
    if (CSRIndex < 0 || CSRIndex >= m_size) {
        throw std::runtime_error("Invalid indexes");
    }

    // go to the correct matrix
    CSR* curr = m_head;
    for (int i = 0; i < CSRIndex; i++) {
        curr = curr->m_next;
    }

    // make sure that there is something 
    if (curr == nullptr) {
        throw std::runtime_error("No item");
    }

    return curr->getAt(row, col);
}


bool CSRList::operator==(const CSRList & rhs) const{
    // check that the size of both linked lists match
    if (m_size != rhs.m_size){
        return false; 
    }

    CSR* curr = m_head; 
    CSR* currRHS = rhs.m_head; 
    
    // goes through the linked list and matches each matrix
    while (curr != nullptr){
        if (!(*curr == *currRHS)) {
            return false;
        }
        curr = curr->m_next;
        currRHS = currRHS->m_next;
    }
    return true; 
}


const CSRList& CSRList::operator=(const CSRList & rhs){
    // check for self assignment
    if(this == &rhs) {
        return *this; 
    }
    
    // deallocate any existsing memory
    clear();

    // copy the rhs items
    CSR* curr = rhs.m_head;
    while (curr != nullptr){
        insertAtHead(*curr);
        curr = curr->m_next; 
    }
    return *this;
}


int CSRList::averageSparseRatio(){
    // if there is nothing in the linked list, return 0; doing this prevents a division by size of 0 
    if (empty()) {
        return 0;
    }

    double total = 0.0;

    //  totals each of the sparse ratio for the matrices
    CSR* curr = m_head;
    while (curr != nullptr) {
        total += curr->sparseRatio();
        curr = curr->m_next;
    }

    return total/m_size; 
}


void CSRList::dump(){
    if (!empty()){
        CSR* temp = m_head;
        while (temp != nullptr){
            temp->dump();
            temp = temp->m_next;
        }
    }
    else
        cout << "Error: List is empty!" << endl;
}