//this file was generated by ../../../../../../scripts/onnx_generator/OperatorTemplate.py
#include "operator__ai_onnx__transpose__1.h"
#include "tracing.h"
#include "utils.h"

operator_status
prepare_operator__ai_onnx__transpose__1(
    node_context *ctx
)
{
    TRACE_ENTRY(1);

    TRACE_NODE(2, true, ctx->onnx_node);

    /* UNCOMMENT AS NEEDED */

    Onnx__TensorProto *i_data = searchInputByName(ctx, 0);

    TRACE_TENSOR(2, true, i_data);

    Onnx__AttributeProto *a_perm = searchAttributeNyName(ctx->onnx_node->n_attribute,ctx->onnx_node->attribute,"perm");

    TRACE_ATTRIBUTE(2, a_perm, a_perm);

    Onnx__TensorProto *o_transposed = searchOutputByName(ctx, 0);

    /* ALLOCATE AND INITIALIZE CONTEXT HERE IF NEEDED */

    size_t default_n_perm  = i_data->n_dims;
    int64_t default_perm[default_n_perm];
    for (int i = 0; i < i_data->n_dims; i++) {
        default_perm[i] = i_data->dims[i_data->n_dims-i-1];
    }

    context_operator__ai_onnx__transpose__1 *op_ctx = NULL;
    op_ctx = malloc(sizeof(context_operator__ai_onnx__transpose__1));
    TRACE_FATAL(0 , !op_ctx, "could not allocate executer_context");

    op_ctx->n_perm = a_perm?a_perm->n_ints:default_n_perm;
    op_ctx->perm = a_perm?a_perm->ints:ARRAYDUP(default_perm,default_n_perm);
    TRACE_FATAL(0, !op_ctx->perm, "malloc failed");

    TRACE_ARRAY(2, true, op_ctx->perm, , op_ctx->n_perm, "%" PRId64);

    /* INITIALIZE OUTPUTS DATA_TYPE AND SHAPE HERE */

    o_transposed->n_dims       = op_ctx->n_perm;
    o_transposed->dims         = malloc(o_transposed->n_dims * sizeof(int64_t));
    o_transposed->has_raw_data = 0;
    o_transposed->data_type    = i_data->data_type;

    for (size_t i = 0; i < op_ctx->n_perm; i++){
      o_transposed->dims[i] = i_data->dims[op_ctx->perm[i]];
    }

    /* MALLOC OUTPUT TENSORS HERE */

    mallocTensorData(o_transposed);

    TRACE_TENSOR(2, true, o_transposed);

    /* CHOOSE EXECUTER AND CONTEXT HERE */
    /* YOU MAY USE THE GENERATED RESOLVER */

    ctx->executer = resolve_operator__ai_onnx__transpose__1(ctx);
    ctx->executer_context = op_ctx;

    TRACE_EXIT(1);

    /* CHANGE RETURN CODE IF THIS PREPARER IS VALID */
    // return OP_ENOSYS;
    return OP_OK;
}