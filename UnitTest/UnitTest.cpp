#include "CppUnitTest.h"
#include "../Lab1/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		List* check;
		List* check2;

		TEST_METHOD_INITIALIZE(setUp) {
			check = new List();
		}

		TEST_METHOD_CLEANUP(cleanUp) {
			delete check;
		}

		TEST_METHOD(check_push_back) {
			check->push_back(1);
			Assert::AreEqual(check->get_size(), (size_t)1);
		}

		TEST_METHOD(check_push_back_2) {
			check->push_back(1);
			check->push_back(2);
			Assert::AreEqual(check->at(1), 2);
		}

		TEST_METHOD(check_push_back_size) {
			check->push_back(1);
			check->push_back(1);
			check->push_back(1);
			Assert::AreEqual(check->get_size(), (size_t)3);
		}

		TEST_METHOD(check_push_front) {
			check->push_front(1);
			Assert::AreEqual(check->get_size(), (size_t)1);
		}

		TEST_METHOD(check_push_front_2) { 
			check->push_back(2); 
			check->push_front(1); 
			Assert::AreEqual(check->at(0), 1); 
		}

		TEST_METHOD(check_push_front_size) {
			check->push_front(1);
			check->push_front(1);
			check->push_front(1);
			Assert::AreEqual(check->get_size(), (size_t)3);
		}

		TEST_METHOD(check_pop_back) {
			try {
				check->pop_back();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Error", e.what());
			}
		}

		TEST_METHOD(check_pop_back_2) {
			check->push_back(1);
			check->push_back(2);
			check->push_back(3);
			check->pop_back();
			try {
				check->at(2);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		TEST_METHOD(check_pop_back_head) {
			check->push_back(1);
			check->pop_back(); Assert::IsTrue(check->IsEmpty());
		}

		TEST_METHOD(check_pop_back_size) {
			check->push_back(1);
			check->push_back(2);
			check->push_back(3);
			check->pop_back();
		}

		TEST_METHOD(check_pop_front) {
			try {
				check->pop_front();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Error", e.what());
			}
		}

		TEST_METHOD(check_pop_front_2) { 
			check->push_back(1);
			check->push_back(2);
			check->push_back(3);
			check->pop_front();
			Assert::AreEqual(check->at(0), 2);
		}

		TEST_METHOD(check_pop_front_head) { 
			check->push_back(1);
			check->pop_front();
			Assert::IsTrue(check->IsEmpty());
		}

		TEST_METHOD(check_pop_front_size) {
			check->push_back(1);
			check->push_back(2);
			check->push_back(3);
			check->pop_front();
			Assert::AreEqual(check->get_size(), (size_t)2);
		}

		TEST_METHOD(check_insert) {
			check->insert(1, 0);
			Assert::AreEqual(check->get_size(), (size_t)1);
		}

		TEST_METHOD(check_insert_size) {
			check->push_back(2);
			check->push_back(3);
			check->insert(1, 0);
			Assert::AreEqual(check->get_size(), (size_t)3);
		}

		TEST_METHOD(check_at) {
			Assert::AreEqual(check->at(0), 3);
		} 
		
		TEST_METHOD(check_at_2) {
			try {
				check->at(200);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		TEST_METHOD(check_remove) {
			check->push_back(1);
			check->remove(0);
			Assert::IsTrue(check->IsEmpty());
		}

		TEST_METHOD(check_remove_index) {
			check->push_back(1);
			check->push_back(2);
			check->remove(0);
			Assert::AreEqual(check->at(0), 2);
		} 
		
		TEST_METHOD(check_remove_size) {
			check->push_back(1);
			check->push_back(2);
			check->push_back(3);
			check->remove(1);
			Assert::AreEqual(check->get_size(), (size_t)2);
		} 
		
		TEST_METHOD(check_get_size) {
			Assert::AreEqual(check->get_size(), (size_t)0);
		}

		TEST_METHOD(check_clear) {
			check->clear();
			Assert::AreEqual(check->get_size(), (size_t)0);
		}

		TEST_METHOD(check_IsEmpty) {
			Assert::IsTrue(check->IsEmpty());
		}

		TEST_METHOD(chec_IsNotEmpty) {
			Assert::IsFalse(check->IsEmpty());
		}

		TEST_METHOD(check_insert14) {
			check->insert(check2, 1);
			Assert::AreEqual(check->get_size(), (size_t)0);
		}
	};
}
