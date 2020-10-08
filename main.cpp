#include <iostream>
#include <string>
#include <sstream>

// Invert String -----------------------------------
std::string f_invert_str(std::string str_to_inv)
{
    std::string str_after_inv;
    for(int i = 0; i < static_cast <int> (str_to_inv.length()) ; i++)
    {
        str_after_inv.insert(0, 1, str_to_inv[i]);
    }
    return str_after_inv;
}
// Palindrom ---------------------------------------
void f_palindrom(std::string num)
{
    std::string  inv_num;
    int per_count{};

    inv_num = f_invert_str(num);

    if(num == inv_num)
    {
        std::cout << inv_num;
        std::cout << " " << per_count << "\n";
    }
    else
    {
       do
       {
           std::stringstream ss;
           int inum, iinv_num;

           ss << num << ' ' << inv_num;
           ss >> inum >> iinv_num;

           inum += iinv_num;
           per_count++;

           num = std::to_string(inum);
           inv_num = f_invert_str(std::to_string(inum));

           if (num == inv_num)
           {
               std::cout << num <<" " << per_count<<"\n" ;
               break;
           }
       }
       while(num != inv_num);
    }
}

// Program -------------------------------------------------------------------------------------

int main()
{
    int t{};
    std::string numstr;
    std::cout << "Enter the number of cases \n";
    std::cin >> t;

    while(t--)
    {
        std::cout << "Enter the number <= 80 \n";
        std::cin >> numstr;
        f_palindrom(numstr);
    }
    return 0;
}
