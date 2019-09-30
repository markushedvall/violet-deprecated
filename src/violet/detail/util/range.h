#ifndef VIOLET_DETAIL_RANGE_H
#define VIOLET_DETAIL_RANGE_H

namespace violet {
namespace detail {

template<typename I>
class Range final {
public:

  Range(I begin, I end) : begin_(begin), end_(end) {}

  I begin() const {
    return begin_;
  }

  I end() const {
    return end_;
  }

private:

  I begin_;
  I end_;

};

template<typename R,
         typename I = decltype(std::begin(std::declval<R>())),
         typename RI = std::reverse_iterator<I>>
Range<RI> reverse(R&& range) {
    return Range<RI>(RI(std::end(range)), RI(std::begin(range)));
}

}
}

#endif
