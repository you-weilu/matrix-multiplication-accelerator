# Systolic Data Setup Spec

The Systolic Data Setup reads from both the Activation BRAM and Weight BRAM and feeds them into the Systolic Array with correct timing for weight-stationary dataflow.

Weight loading (before compute): columns of the Weight BRAM are fed into the top of the array and shift downward. Each PE captures its weight value as it passes through.

Activation feeding (during compute): the activation matrix must be transformed before feeding into the array. Columns of A are fed into the rows of the PE array i.e. column k of A is fed into row k of the PE array. This means the Systolic Data Setup reads A in column order applies skewing so that each element meets the correct weight at the correct PE at the correct time.
