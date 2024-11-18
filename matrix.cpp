#include<iostream>
#include<vector>

using namespace std;

class matrix{
    int rows;
    int columns;

    public:
    vector<vector<int>>Arr;
    
    
    matrix ( int r, int c , int init_value =0){
        rows =r;
        columns =c;
        Arr = vector<vector<int>>(r,vector<int>(c,init_value));

    }

   void print() const  
   {

    for (int i = 0 ; i < rows ; i++)
    {
        for ( int j = 0 ; j< columns ;j++)
        {
            cout<<" element row"<<i <<" , coloumn"<<j << "  :"<<Arr[i][j]<<" \n";
        }
    }
   }

   void setvalue( const vector<vector<int>>&obj)
   {
     
     rows = obj.size();

     columns  = rows > 0 ? obj[0].size():0;

     Arr= obj;
}

 matrix operator+(matrix &object) const
{
    int ro = object.Arr.size();
    int co = ro> 0? object.Arr[0].size():0;
    



    if ( ro != rows || co !=  columns)
    {  
        cout<<" Didn't have same deminsion as  the call matrix \n ";

        return matrix(0,0);
    }

    matrix res(rows, columns,0);

    for  ( int i = 0 ; i< ro ; i++)
    {
        for  ( int j = 0 ; j < co ; j++)
        {
            res.Arr [i][j] = Arr[i][j] + object.Arr[i][j];



        }
    }
   

  return res;





}

    matrix& operator++() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                Arr[i][j] = Arr[i][j] + 1;  // Increment each element
            }
        }
        return *this;  // Return the matrix reference
    }



   matrix operator*(matrix const &object)
    {
        if (columns != object.Arr[0].size())
        {
            cout<<" Dimension  are not correct \n";
            return matrix(0,0);
        }
         int n = object.Arr.size();

        matrix  result(n,n,0);
        result.Arr;

        for ( size_t i = 0 ; i< n; i++ )
        {
            for ( size_t j = 0 ; j < n ; j++)
            {
                for ( size_t k = 0 ; k < n ; k++)
                {
                    result.Arr[i][j] =    result.Arr[i][j] + Arr[i][k]*object.Arr[k][j];
                    
                }
            }
        }


        return result;
    }


};

int main ()
{
 vector<vector<int>> Array ={{1,2},{3,4}};
    int n =  Array.size();
    int m =  Array[0].size();
matrix clone(n,m);
clone.setvalue(Array);
// clone.print();
// cout<<"\n";

matrix clone_2(n,m);
clone_2.setvalue(Array);

matrix clone_3(n,m);

clone_3 = clone_2 + clone;
clone_3.print();
         

cout<<"\n after\n";

++clone_3;

clone_3.print();


cout<<"\n";
clone_3 = clone_2*clone;

clone_3.print();

    return 0;





  

}