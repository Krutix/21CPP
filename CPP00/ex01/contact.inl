inline Contact::Contact(std::string const& fn,
        std::string const& ln,
        std::string const& nn,
        std::string const& pn,
        std::string const& ds)
    : first_name(fn),
      last_name(ln),
      nickname(nn),
      phone_number(pn),
      darkest_secret(ds) {}

inline void Contact::set_first_name(std::string const& fn) { this->first_name = fn; }
inline void Contact::set_last_name(std::string const& ln) { this->last_name = ln; }
inline void Contact::set_nickname(std::string const& nn) { this->nickname = nn; }
inline void Contact::set_phone_number(std::string const& pn) { this->phone_number = pn; }
inline void Contact::set_dargest_secret(std::string const& ds) { this->darkest_secret = ds; }
inline std::string const& Contact::get_first_name() const { return this->first_name; }
inline std::string const& Contact::get_last_name() const { return this->last_name; }
inline std::string const& Contact::get_nickname() const { return this->nickname; }
inline std::string const& Contact::get_phone_number() const { return this->phone_number; }
inline std::string const& Contact::get_dargest_secret() const { return this->darkest_secret; }
