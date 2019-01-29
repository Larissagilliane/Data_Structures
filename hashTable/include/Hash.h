#ifndef _HASH_
#define _HASH_

#include <functional>
#include <string>
#include <list>

/**
 * \brief Classe que representa a hash_table
 * */
template<typename KeyType, typename DataType>
class HashEntry {
	public:
		HashEntry (KeyType _k, DataType _d) : key {_k}, data{_d} {};
		KeyType key;
		DataType data;
};

template<typename KeyType, typename DataType, typename KeyHash = std::hash<KeyType>, typename KeyEqual = std::equal_to<KeyType>>
class HashTbl {
	public:
		
		typedef HashEntry <KeyType, DataType> Entry;

		/**
		 * \brief construtor.
		 * \param[in] _tblSize tamanho.
		 * */
		HashTbl (unsigned int _tblSize = DEFAULT_SIZE);

		/**
		 * \brief Destrutor (fiz dessa vez...haha).
		 * */
		virtual ~HashTbl();
		
		/**
		 * \brief Adiciona informação
		 * \param[in] _k  key.
		 * \param[in] _d  informação a ser inserida
		 * \return false, se a chave existir e a informação for subescrita, true caso contrário.
		 * */
		bool insert (const KeyType & _k, const DataType & _d) throw (std::bad_alloc);
		
		/**
		 * \brief Remove
		 * \param[in] _k key.
		 * \return true, se a chave existir; false caso contrário.
		 * */
		bool remove (const KeyType & _k);
		
		/**
		 * \param[in] _k  key.
		 * \param[out] _d a informação.
		 * \return true, se a chave existir; false caso contrário.
		 * */
		bool retrieve (const KeyType & _k, DataType & _d) const;
		
		/**
		 * \brief Limpa
		 * */
		void clear (void);

		/**
		 * \brief Checa se esta vazia
		 * \return true se estiver vazia, false caso contrario 
		 * */
		bool empty (void) const;
		
		/**
		 * \brief Numero de elementos da tabela
		 * */
		unsigned long int count (void) const;

		/**
		 * \brief Mostra a tabela em string
		 * */
		void showStructure(void) const;
	private:
		unsigned int size;				
		unsigned int countElements; 			
		std::list<Entry> * dataTable;			
		static const short DEFAULT_SIZE = 10;		
				
		/**
		 * \brief hash correspondente para a seguinte key
		 * \param[in] _k  key.
		 * \returns hash correspondente
		 * */
		size_t performHash(const KeyType & _k) const;
		
		/**
		 * \param[in] _k key.
		 * \param[out] it Iterator
		 * \returns True se encontrado, false caso contrário
		 * */
		bool search(const KeyType & _k, typename std::list<Entry>::iterator & it) const;	
};

#include "../src/HashTable.cpp"
#endif
