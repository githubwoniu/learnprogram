```c++
class Solution {
public:
    bool isValid(string s) {
        char  elem=0,left_elem=0,right_elem=0;
        Stack *ptr = new Stack( (int)s.length() );
        for( int i=0;i<s.size();i++ )
        {
            elem = s[i];
            switch( elem )
            {
            case '[':
            case '(':
            case '{':
            ptr->PushStack(elem);
            break;
            case ']':
            case ')':
            case '}':
            {
                ptr->GetTopStack(left_elem);
                switch( left_elem )
                {
                    case '[':
                    right_elem = ']';
                    break;
                    case '(':
                    right_elem = ')';
                    break;
                    case '{':
                    right_elem = '}';
                    break;
                }
                if( right_elem == elem )
                {
                    ptr->PopStack();
                    break;
                }
                else
                {        
                    delete ptr;
                    return false;
                }
            }
            default:
            {
                delete ptr;
                return false;
            }

            }
        }
        if(ptr->IsEmptyStack())
        {
            delete ptr;
            return true;
        }
        delete ptr;
        return false;
    }
class Stack{
public:
    Stack( int size )
    {
        m_size = size;
        m_ptr = new char[size];
        memset( m_ptr, 0x00, size );
        m_top = 0;
    }
    ~Stack()
    {
        delete []m_ptr;
        m_top = 0;
        m_size = 0;
    }
    bool IsFullStack()
    {
        return m_size == m_top;
    }
    bool IsEmptyStack()
    {
        return m_top ==0;
    }
    bool PushStack( char elem )
    {
        if( IsFullStack() )
            return false;
        m_ptr[m_top] = elem;
        m_top++;
        return true;
    }
    bool PopStack( )
    {
        if( IsEmptyStack())
            return false;
        m_top--;
        return true;
    }
    bool GetTopStack( char& elem )
    {
        if( IsEmptyStack() )
            return false;
        elem = m_ptr[m_top-1];
        return true;
    }
private:
    char* m_ptr;
    int   m_top;
    int   m_size;
};

    
};
```
