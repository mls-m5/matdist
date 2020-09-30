#pragma once

#include "icompiler.h"
#include <iosfwd>

//! The streamcompiler is expected to read source code from the input stream and
//! output opbject data to the output stream
class IStreamCompiler : public virtual ICompiler {
public:
    //! Set stream for data going into the compiler
    //! Only valid before compile() is called
    virtual std::ostream &input() = 0;

    //! Stream for data going out of the compiler
    //! Only valid after compile() is called
    virtual std::istream &output() = 0;

    //! If the output stream is valid
    virtual operator bool() = 0;

    //! Helper functions
    template <typename T>
    std::ostream &operator<<(const T &value) {
        input() << value;
        return input();
    }

    template <typename T>
    std::istream &operator>>(T &value) {
        output() >> value;
        return output();
    }
};
