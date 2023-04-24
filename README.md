# arduino-fingerprint


#finger.getImage() is a method call that captures a fingerprint image from the Adafruitfingerprint sensor module and returns a value that indicates whether the image capture was successful or not.

#The value returned by finger.getImage() is not the fingerprint ID itself, but rather a status code that indicates the result of the image capture operation.

#The method call finger.fingerID() is used in the example sketch I provided to obtain the unique ID of the fingerprint that was just captured. This method call returns the ID of the last fingerprint that was successfully identified by the sensor module.

Here is a brief summary of the two method calls and what they do:

#finger.getImage(): Captures a fingerprint image from the sensor module and returns a status code indicating the result of the image capture operation. This method call is used to detect whether a finger is present on the sensor and capture the fingerprint image data.

#finger.fingerID(): Returns the unique ID of the last fingerprint that was successfully identified by the sensor module. This method call is used to obtain the ID of the fingerprint that was just captured, so that it can be stored in the database or compared to other fingerprint IDs in the database for authentication purposes.
