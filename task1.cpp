#include <iostream>
#include <cassert>
class ArrayInt {
    private:
        int *m_data;
        int m_length;
    public:
        ArrayInt () : m_length (0), m_data(nullptr) {

        }
        ArrayInt (int length) : m_length (length) {
            assert (length >=0);
            if (length > 0)
                m_data = new int[length];
            else
                m_data = nullptr;
        }
        ~ArrayInt(){
            delete [] m_data;
        }
        void clear (){
            delete [] m_data;
            m_data = nullptr;
            m_length = 0;
        }
        int size () const {
            return m_length;            
        }
        int& operator[](int index){
            assert (index >=0 && index < m_length);
            return m_data[index];
        }
        void resize (int newLength) {
            if (newLength == m_length)
                return;
            if (newLength <= 0) {
                clear();
                return;
            }
            int *data = new int [newLength];
            int elementsToCopy = newLength > m_length ? m_length : newLength;
            for (int i = 0; i < elementsToCopy; ++i)
                data[i] = m_data[i];
            delete [] m_data;
            m_data = data;
            m_length = newLength;
        }
        void insertBefore (int value, int index) {
            
            assert (index >= 0 && index <= m_length);
            
            int *data = new int [m_length+1];
            
            for (int before = 0; before < index; ++before)
                data[before] = m_data[before];
            data [index] = value;

            for (int after = index; after < m_length; ++after)
                data[after+1] = m_data[after];
            
            delete [] m_data;
            m_data = data;
            ++m_length;
        }
        void push_back (int value) {
            insertBefore (value, m_length);
        }
        void print () const {
            std::cout << "Array is " << m_length <<  " element [";
            for (int i = 0; i< m_length; i++) {
                std::cout <<m_data[i] << " ";
            }
            std::cout << "]";
        }
        void print (int i) {
            assert (i > 0 && i < m_length);
            std::cout << i << "-element array is value "<< m_data [i] << std::endl;
        }
        void pop_back () {
            int *data = new int [m_length-1];
            for (int i=0; i<m_length-1; i++) {
                data [i]= m_data[i];
            }
            delete [] m_data;
            m_data = data;
            --m_length;
        }

        void pop_front () {
            int *data = new int [m_length-1];
            for (int i=1; i<m_length; i++) {
                data [i-1] = m_data [i];
            }
            delete [] m_data;
            m_data = data;            
            --m_length;
            
        }
   
    void sort() {
	    for (int startIndex = 0; startIndex < m_length - 1; ++startIndex) {
		    int smallestIndex = startIndex;
		    for (int currentIndex = startIndex + 1; currentIndex < m_length; ++currentIndex) {
			    if (m_data[currentIndex] < m_data[smallestIndex])
				    smallestIndex = currentIndex;
		    }
		    std::swap(m_data[startIndex], m_data[smallestIndex]);
	    }
    }
};
int main () {
    ArrayInt array(1);
    array.push_back (1);
    array.push_back (2);
    array.push_back (13);
    array.push_back (4);
    array.push_back (52);
    array.push_back (16);
    array.push_back (7);
    array.push_back (82);
    array.push_back (921);
    array.push_back (10);
    array.push_back (111);
    array.push_back (12);
    array.push_back (131);
    array.push_back (114);
    array.push_back (15);
    array.push_back (16);
    array.sort ();
    array.print ();
    array.resize (9);
    array.resize (16);
    array.print ();
    array.pop_back ();
    array.pop_back ();
    array.pop_back ();
    array.pop_back ();
    array.pop_back ();
    array.pop_back ();
    array.pop_front ();
    array.pop_back ();
    array.pop_front ();
    array.pop_front (); 
    array.sort ();
    array.print ();
    //std::cout << array.size ();
    return 0;
}
