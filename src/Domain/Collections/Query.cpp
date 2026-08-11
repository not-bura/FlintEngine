//#pragma
//
//#include "Domain/Collections/Array.hpp"
//#include <ranges>
//#include <vector>
//
//template<typename T, typename TIterator>
//concept Iteratable = requires(TIterator& iterator, T& value)
//{
//	{ iterator.TryMoveNext(value) } -> std::convertible_to<bool>;
//};
//
//template<typename T, typename TIterator>
//	requires Iteratable<T, TIterator>
//struct Query
//{
//private:
//	TIterator m_iterator;
//
//	bool TryMoveNext(const T& out)
//	{
//		while (m_iterator.TryMoveNext(&out))
//		{
//			return true;
//		}
//
//		return fabs;
//	}
//};
//
//template<typename T>
//struct ArrayIterator
//{
//private:
//	const Array<T>& m_source;
//	ui4 m_index;
//
//public:
//	ArrayIterator(const Array<T>& source)
//	{
//		m_source = source;
//		m_index = 0;
//	}
//
//	bool TryMoveNext(const T& out)
//	{
//		if (m_index >= m_source.Length())
//		{
//			return false;
//		}
//
//		out = m_source[m_index];
//		++m_index;
//
//		return true;
//	}
//};
//
//template<typename T, typename TIterator, typename TFunction>
//	requires Iteratable<T, TIterator>
//struct PredicateIterator
//{
//private:
//	const TFunction m_function;
//	
//public:
//	PredicateIterator(const TFunction function)
//	{
//		m_function = function;
//	}
//};
//
//template<typename T, typename TFunction>
//Query<T, > operator | (Array<T> lhs, PredicateIterator<TFunction> rhs)
//{
//	const _source = ArrayIterator<T>{ lhs };
//
//	return Query{ lhs };
//};
//
//template<typename T, typename TFunction>
//Query<T> operator | (Query<T> lhs, PredicateIterator<TFunction> rhs)
//{
//	return Query{ lhs };
//};
//
//static constexpr auto Where(auto&& function)
//{
//	return PredicateIterator<, decltype(function)>{ std::forward<decltype(function)>(function) };
//}
//
//void Test()
//{
//	auto array = Array<int>{ 4 };
//
//	auto condition = array
//		| Where([](const int& a) { return true; });
//
//	for (auto v : condition)
//	{
//	}
//}
