
//this file was generated by ../../../scripts/onnx_generator/OperatorSanityCheck.py
#include "operators/check_operator.h"
#include "operators/onnx/operator__onnx__add__7.h"

bool check_operator__onnx__add__7(
    size_t                  n_input,
    Onnx__TensorProto    ** input,
    size_t                  n_attribute,
    Onnx__AttributeProto ** attribute,
    size_t                  n_output,
    Onnx__TensorProto    ** output
){
    bool valid = true;
    { // check if input tensors have valid types
        uint32_t types_A[7] = {
            ONNX__TENSOR_PROTO__DATA_TYPE__DOUBLE,
            ONNX__TENSOR_PROTO__DATA_TYPE__FLOAT,
            ONNX__TENSOR_PROTO__DATA_TYPE__FLOAT16,
            ONNX__TENSOR_PROTO__DATA_TYPE__INT32,
            ONNX__TENSOR_PROTO__DATA_TYPE__INT64,
            ONNX__TENSOR_PROTO__DATA_TYPE__UINT32,
            ONNX__TENSOR_PROTO__DATA_TYPE__UINT64
        };
        uint32_t types_B[7] = {
            ONNX__TENSOR_PROTO__DATA_TYPE__DOUBLE,
            ONNX__TENSOR_PROTO__DATA_TYPE__FLOAT,
            ONNX__TENSOR_PROTO__DATA_TYPE__FLOAT16,
            ONNX__TENSOR_PROTO__DATA_TYPE__INT32,
            ONNX__TENSOR_PROTO__DATA_TYPE__INT64,
            ONNX__TENSOR_PROTO__DATA_TYPE__UINT32,
            ONNX__TENSOR_PROTO__DATA_TYPE__UINT64
        };
        check_operator_condition_tensor conditions[2] = {
            {
                .skip = false,
                .name = "A",
                .optional = false,
                .n_types = 7,
                .types  = types_A
            },{
                .skip = false,
                .name = "B",
                .optional = false,
                .n_types = 7,
                .types  = types_B
            }
        };
        valid &= check_operator_tensors("operator__onnx__add__7 input",
                                         2,
                                         conditions,
                                         input);
    }
    { // check if output tensors have valid types
        uint32_t types_C[7] = {
            ONNX__TENSOR_PROTO__DATA_TYPE__DOUBLE,
            ONNX__TENSOR_PROTO__DATA_TYPE__FLOAT,
            ONNX__TENSOR_PROTO__DATA_TYPE__FLOAT16,
            ONNX__TENSOR_PROTO__DATA_TYPE__INT32,
            ONNX__TENSOR_PROTO__DATA_TYPE__INT64,
            ONNX__TENSOR_PROTO__DATA_TYPE__UINT32,
            ONNX__TENSOR_PROTO__DATA_TYPE__UINT64
        };
        check_operator_condition_tensor conditions[1] = {
            {
                .skip = false,
                .name = "C",
                .optional = false,
                .n_types = 7,
                .types  = types_C
            }
        };
        valid &= check_operator_tensors("operator__onnx__add__7 output",
                                         1,
                                         conditions,
                                         output);
    }
    { // check if attributes have valid types
        check_operator_condition_attribute conditions[0] = {
            
        };
        valid &= check_operator_attributes("operator__onnx__add__7",
                                           0,
                                           conditions,
                                           attribute);
    }
    { // check if multiple tensors constrained by 'T' have same type
        check_operator_condition_constraint conditions_input[2] = {
            {
                .skip = false,
                .name = "A",
                .optional = false
            },{
                .skip = false,
                .name = "B",
                .optional = false
            }
        };
        check_operator_condition_constraint conditions_output[1] = {
            {
                .skip = false,
                .name = "C",
                .optional = false
            }
        };
        valid &= check_operator_constraint("operator__onnx__add__7 T",
                                           2,
                                           conditions_input,
                                           input,
                                           1,
                                           conditions_output,
                                           output);
    }
    return valid;
}
