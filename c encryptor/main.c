/*

Below is a program to encrypt and decrypt
plaintext files. Utilizes a one-time-pad
style method. This should take a rather long
time to break.

Author - Kuba Gasiorowski

*/

#include "encr_func.h"
#include "helpers.h"

int main(int argc, char *argv[])
{

    Arg_data *argdata = parse_args(argv, argc);
    
    if(argdata->error == true)
        usage(EXIT_FAILURE);
    
    if(argdata->ui)
    {

        return prgm_ui();

    }

    
    
    return 0;
	
}


