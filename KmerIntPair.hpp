#ifndef BFC_KMER_INT_PAIR_HPP
#define BFC_KMER_INT_PAIR_HPP

#include "Kmer.hpp"

// TODO: switch out for a templated version
struct KmerIntPair {
  KmerIntPair() {};
  KmerIntPair(const Kmer &km, unsigned int k);

  char v[sizeof(Kmer)+sizeof(char)];
  unsigned int GetVal() const;
  void SetVal(const unsigned int k);
  bool ParallelIncrement();
  const Kmer& GetKey() const;
  void SetKey(const Kmer& km);

  static const unsigned int MaxVal = 255;
  static const size_t KmerOffset = 0;
  static const size_t IntOffset = sizeof(Kmer);
};



struct SelectKmerKey {
  typedef Kmer result_type;
  typedef Kmer key_type;
  typedef const Kmer& argument_type;

  result_type operator()(const KmerIntPair &p) const {
    return p.GetKey();
  }

  result_type operator()(const KmerIntPair *p) const {
    return p->GetKey();
  }
};

struct SetKmerKey {
  using result_type = void;
  void operator()(KmerIntPair* value, const Kmer& km) const {
    value->SetKey(km);
  }
};


#endif // BFC_KMER_INT_PAIR_HPP
