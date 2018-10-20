#ifndef CONTACT_INFO_HPP
#define CONTACT_INFO_HPP

struct ContactInfo{
    ContactInfo(char const * name, char const * email);
    ContactInfo(ContactInfo const & contact_info) = delete; // Copy constructor
    ContactInfo(ContactInfo && contact_info); // Mutable (non-const) rvalue ref. Move constructor.
    ~ContactInfo();

private:
    char const * name;
    char const * email;
};


#endif
