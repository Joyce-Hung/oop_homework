class Example
{
public:
    Example( int y=10 )
        :data(y)
    {

    }
    int getIncrement() const/*Error : This function is declared "const", but it modified 
                            the object "data".
                            Correction : Remove the keyword "const" from the definition 
                                of this function.*/ 
    {
        return data++;
    }
    static int getCount()/*Error : Since this function is declared "static", it isn't
                        allowed to access the non-static member "data"  of the class.
                        Correction : Remove the output line(20) from this function.  */
    {
        cout<< "Data is "<<data<<endl;
        return count;
    }
private:
    int data;
    static int count;
};