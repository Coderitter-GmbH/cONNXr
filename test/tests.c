#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/onnx.pb-c.h"
#include "test_utils.h"

// Operators tests
#include "operators/test_operator_add.h"
#include "operators/test_operator_argmax.h"
#include "operators/test_operator_matmul.h"
#include "operators/test_operator_sigmoid.h"
#include "operators/test_operator_softmax.h"

// Model tests
#include "models/test_model_mnist.h"

// Common stuff
#include "operators/common_operators.h"
#include "models/common_models.h"

int main (void)
{
  CU_pSuite operatorsTestSuite = NULL;
  CU_pSuite modelsTestSuite = NULL;

  // Initialize CUnit test registry
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  // Operators test suite and test cases
  operatorsTestSuite = CU_add_suite("Operators_TestSuite",
                                    init_Operators_TestSuite,
                                    clean_Operators_TestSuite);
  if (NULL == operatorsTestSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  // Add tests for Operators test suite
  if ((NULL == CU_add_test(operatorsTestSuite, "test_matmul_2d", test_matmul_2d)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(operatorsTestSuite, "test_Operators_Add", test_Operators_Add)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(operatorsTestSuite, "test_Operators_Sigmoid", test_Operators_Sigmoid)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(operatorsTestSuite, "test_Operators_Softmax", test_Operators_Softmax)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(operatorsTestSuite, "test_Operators_ArgmMax", test_Operators_ArgMax)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  // Models test suite and test cases
  modelsTestSuite = CU_add_suite("Models_TestSuite",
                                 init_Models_TestSuite,
                                 clean_Models_TestSuite);
  if (NULL == modelsTestSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if ((NULL == CU_add_test(modelsTestSuite, "test_model_mnist", test_model_mnist)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();

}
