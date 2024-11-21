#!/usr/bin/env python3.8

with open( "exceptionList", "r", encoding="utf-8" ) as file:
    names = file.readlines()
    for index, line in enumerate( names ):
        names[ index ] = line.rstrip() 

with open( "Exceptions.h", "w", encoding="utf-8" ) as outFile:
    outFile.write( "#ifndef _JAM_EXCEPTIONS_H\n#define _JAM_EXCEPTIONS_H\n\n#include <stdexcept>\n#include <string>\n\nnamespace Jam\n{\n" )

    for name in names:
        if ( name == "" or name[0] == "#" ):
            continue

        outFile.write( f"\tclass {name} : public std::runtime_error\n" )
        outFile.write( "\t{\n\tpublic:\n\t\t" )
        outFile.write( f"explicit {name}(const std::string& message ) : std::runtime_error( message )" + " {}\n" )
        outFile.write( "\t};\n\n" )

    outFile.write( "}\n\n#endif // _JAM_EXCEPTIONS_H" )

