const tf = require('@tensorflow/tfjs');
require('@tensorflow/tfjs-node');

const tensor = tf.tensor([[1,2],[3,4]]);

tensor.print();
