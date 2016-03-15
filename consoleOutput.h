#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H

#include "OutputBase.h"
#include <iostream>


class consoleOutput : public OutputBase
{
public:
    consoleOutput(std::ostream& o):outfile(o)
    {}
    virtual ~consoleOutput() = default;

    virtual void put(std::string const& /*e*/,Rect const&,SizeFactor /*sizefactor*/) override
    {
//        send(outfile,e); //send 需要被提供
    }
    std::ostream& outfile;
};

#endif // CONSOLEOUTPUT_H
