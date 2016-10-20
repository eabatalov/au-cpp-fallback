#include <string.h>
#include <utility>

#include "lazy_string.h"
namespace lazy {

lazy_string::lazy_string(size_t buf_size)
    : buf_(buf_size)
{}

lazy_string::lazy_string(const char *src)
    : lazy_string(strlen(src) + 1)
{
    memcpy(buf_.get_data(), src, buf_.get_size());
}

lazy_string::lazy_string(const lazy_string &src)
    : buf_(src.buf_)
{}

lazy_string::lazy_string(lazy_string &&src)
    : buf_(src.buf_)
{}

bool lazy_string::empty() const
{
    return buf_.get_size() == 1;
}

size_t lazy_string::get_size() const
{
    return buf_.get_size() - 1;
}

char lazy_string::get_at(size_t ix) const
{
    return buf_.get_data()[ix];
}

const char* lazy_string::c_str() const
{
    return buf_.get_data();
}

lazy_string& lazy_string::operator=(lazy_string src)
{
    std::swap(buf_, src.buf_);
    return *this;
}

void lazy_string::set_at(size_t ix, char value)
{
    shared_buffer changed_buf(buf_.get_size());
    memcpy(changed_buf.get_data(), buf_.get_data(), buf_.get_size());
    changed_buf.get_data()[ix] = value;
    buf_ = changed_buf;
}

} //namespace lazy
