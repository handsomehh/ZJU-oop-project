#pragma once
#include<iostream>
#include<cassert>
#define DEBUG_STATE 0

#if DEBUG_STATE
	int count1[1024/8][2] = {0};
#endif
namespace Alloc {
	const size_t SEG_SIZE = 8;//step between different block in memory
	const size_t MAX_SIZE = 1024;//maxsize for memory block
	const size_t CHUNK_NUM = 8;//memory blocks' number of every allocating
	const size_t FREELIST_SIZE = MAX_SIZE / SEG_SIZE;//freelist's size
#define INDEX_SEG(e) (((((e)+SEG_SIZE-1)&~(SEG_SIZE-1))>>3)-1)//index calculator
	
	struct Freelist_node {//freelist's node,store address mainly
		struct Freelist_node* next;
	};

	template <class _Ty>
	class MyAllocator
	{
	public:
		/*---value definition and typedef here---------*/
		typedef void _Not_user_specialized;
		typedef _Ty value_type;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef size_t size_type;
		static inline struct Freelist_node* free_list[FREELIST_SIZE] = { nullptr };//freelist
		template<class T>
		struct rebind { typedef MyAllocator<T> other; };
		/*-----------function is defined here ------------*/
		MyAllocator() {}//constructor

		template<class T>
		MyAllocator(const MyAllocator<T>& a) {}//constructor

		~MyAllocator() {}//destructor

		inline size_type max_size() {//retunrn maxsize of a valuetype 
			return size_type(UINT_MAX / sizeof(value_type));
		}

		inline pointer address(reference _Val) {//call std::addressof to get address of val
			return std::addressof(_Val);
		}
		inline const_pointer address(const_reference _Val) {//call std::addressof to get address of val
			return std::addressof(_Val);
		}
		static inline void deallocate(pointer ptr, size_type count) {//deallocate function
			size_t size_sum = count * sizeof(value_type);//calculate size of block we will deallocate
			if (size_sum > MAX_SIZE) {//if size is bigger than maxsize, free directly
				free(ptr);
				return;
			}
			else {//put freelist's head to this block
				((Freelist_node*)ptr)->next = free_list[INDEX_SEG(size_sum)];
				free_list[INDEX_SEG(size_sum)] = (Freelist_node*)ptr;
			}
		}
		static  pointer allocate(size_type count) {//allocate function
			size_t size_sum = count * sizeof(value_type);//calculate size of block
			if (size_sum > MAX_SIZE) {//if size is bigger than maxsize, malloc directly
				char *buf = (char*)std::malloc(size_sum);//use a buffer to store block
				if (!buf) {//allocate fail
					std::cout << "memory overflow" << std::endl;
					throw "error";//throw exception
				}
				return (pointer)buf;//return address of the buf
			}
			Freelist_node* cur;
			Freelist_node* des;
			des = free_list[INDEX_SEG(size_sum)];
			if (des == nullptr) {
#if DEBUG_STATE
				count1[INDEX_SEG(size_sum)][0]++;//use in debug,record freelist's message
				count1[INDEX_SEG(size_sum)][1]=0;
				std::cout << "申请内存空间的大小:" << size_sum << " freelist 下标:" << INDEX_SEG(size_sum) << std::endl;
#endif
				return (pointer)CallForMem(size_sum, INDEX_SEG(size_sum));//freelist is null, call for memory
			}
#if DEBUG_STATE
			count1[INDEX_SEG(size_sum)][1]++;
#endif
			free_list[INDEX_SEG(size_sum)] = free_list[INDEX_SEG(size_sum)]->next;//update freelist
			return (pointer)des;
		}
		template<class Ut>
		static inline void destroy(Ut* p) {//destory, use destructor function directly
			p->~Ut();
		}
		template<class Ut, class Pt>
		static inline void construct(Ut* p, Pt argv) {//constructor , use constructor function directly
			new(p) Ut(argv);
		}
		private:
			inline static char* CallForMem(size_t size_to_call, int index) {//call for memory by this function
				Freelist_node* temp = nullptr;
				size_t all = 7;
				size_t align_to_eight = ((size_to_call + 7) & ~all);//find the nearest number of times of 8
				char* buf = (char*)std::malloc(CHUNK_NUM * align_to_eight);//allocate
				if (!buf) {
					std::cout << "out of memory" << std::endl;//allocate fail
					throw "error";
				}
				char* record = buf + align_to_eight;
				for (int i = 0; i < CHUNK_NUM - 1; i++) {//link node one by one
					if (i == 0) {
						free_list[index] = (Freelist_node*)record;
						temp = (Freelist_node*)record;
						temp->next = nullptr;
						record += align_to_eight;
					}
					else {
						temp->next = (Freelist_node*)record;
						temp = temp->next;
						temp->next = nullptr;
						record += align_to_eight;
					}
				}
				return buf;
			}
	};
}