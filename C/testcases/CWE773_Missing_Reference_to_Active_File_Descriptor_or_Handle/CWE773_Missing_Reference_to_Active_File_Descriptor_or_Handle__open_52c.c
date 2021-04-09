/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52c.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open.label.xml
Template File: source-sinks-52c.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file descriptor using open()
 * Sinks:
 *    GoodSink: Close the file before reusing the file descriptor
 *    BadSink : Reassign the file descriptor before closing the file
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

#ifndef OMITBAD

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52c_badSink(int data)
{
    /* FLAW: Assign data to another file descriptor without closing the descriptor from the source */
    data = OPEN("BadSink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* avoid incidental for not closing the file */
    if (data != -1)
    {
        CLOSE(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52c_goodB2GSink(int data)
{
    /* FIX: Close the file from the source before reassigning data to a new file descriptor */
    if (data != -1)
    {
        CLOSE(data);
    }
    data = OPEN("GoodSink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* avoid incidental for not closing the file */
    if (data != -1)
    {
        CLOSE(data);
    }
}

#endif /* OMITGOOD */
