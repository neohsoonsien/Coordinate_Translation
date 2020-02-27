# include <fstream>
using namespace std;

bool true_or_false; // to define boolean expression globally

void path_return(const int & x1, const int & y1, const int & x2, const int & y2)
{
    if (y2 >= y1 && x2 >= x1) // to ensure that coordinate translation must be to the top and to the right
    {
        if ((x1 != 0 && y1 != 0)
                && ((x2 - x1) % y1 == 0) && ((y2 - y1) % x1 == 0))              // coordinates does n't coincide on x-axis and y-axis
            true_or_false = true;
        else if ((x1 == 0 && y1 != 0) && ((x2 - x1) % y1 == 0) && (y2 == y1))   // coordinates coincide with y-axis
            true_or_false = true;
        else if ((x1 != 0 && y1 == 0) && ((y2 - y1) % x1 == 0) && (x2 == x1))   // coordinates coincide with x-axis
            true_or_false = true;
        else if ((x1 == 0 && y1 == 0) && (x2 == 0 && y2 == 0))                  // special translation from (0, 0) to (0, 0) only
            true_or_false = true;
        else
            true_or_false = false;
    }
    else
        true_or_false = false;
}

int main()
{
    ifstream input;
    input.open("Input.txt"); // to provide input
    
    ofstream output;
    output.open("Output.txt"); // to give output

    int test_case_number;
    int x1, y1, x2, y2;

    // the first line in the  "Input.txt" will tell how many test cases
    input >> test_case_number;
    for (int example = 0; example < test_case_number; example++)
    {
        input >> x1 >> y1 >> x2 >> y2; // to read in coordinates
        path_return(x1, y1, x2, y2); // to save a globally define \d boolean expression

        // to print out the results to the "Output.txt"
        output << "Test case number " << example + 1 << ", and the path return possibility is ";
        if (true_or_false)
            output << "True" << endl;
        else
            output << "False" << endl;
    };

    // to close the files
    input.close();
    output.close();

    return 0;
}
