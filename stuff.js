/**
 * Function to create an object 
 */
function createMyObject() {
    var myObject = {
      foo:'bar',
      answerToUniverse: 42,
      'olly olly': 'oxen free',
      sayHello: function() {
        return 'hello';
      }
    };
    
    return myObject
  }

  /**
   * Function to update/add some attributes to the object passed
   * 
   * @param {object} obj         The object to update/add to
   */
  function updateObject(obj) {
    obj.foo = 'foo';
    obj.bar = 'bar';
    obj.bizz = 'bizz';
    obj.bang = 'bang';
    
    return obj;
  }

  /**
   * Function to use self referrential keyword "this" in an attibute function
   */
  function personMaker() {
    var person = {
      firstName: 'Paul',
      lastName: 'Jones',
      // full name
      fullName: function() {
        return this.firstName + ' ' + this.lastName;
      }
    };
    return person;
  }

  /**
   * Function to delete attributes to a given object
   * 
   * @param {object} obj            The object to delete from
   */
  function keyDeleter(obj) {
    delete obj.foo;
    delete obj.bar;
    
    return obj;
  }

  /**
   * Function to iterate over an array of objects of students data, and return an array of strings of which contains a summary
   * 
   * @param {array of obejects} data            The array of objects to make a report of
   */
  function makeStudentsReport(data) {
    var myArray = [];
    
    data.forEach(function(student) {
      myArray.push(student.name + ": " + student.grade);
    });
    
    return myArray;
  }

  /**
   * Function to iterate over an array and return another array of objects with all attributes the same except change the status to "In Summer school"
   * 
   * @param {array of objects} students         The array of students to change the status of
   */
  function enrollInSummerSchool(students) {
    return students.map(function(student) {
      return {
        name: student.name,
        status: "In Summer school",
        course: student.course
      };
    });
  }

  /**
   * Function to find the object with a specified id in an array of objects
   * 
   * @param {array of objects} items            The array of items to look in
   * @param {number} idNum                      The id to search for
   */
  function findById(items, idNum) {
    return items.find(function(item) {
      return item.id === idNum;
    });
   }

   /**
    * Function to pass in an object and validate the keys in the object
    * 
    * @param {object} object                        // The object to validate
    * @param {array of strings} expectedKeys        // The array of expected keys to validate from
    */
   function validateKeys(object, expectedKeys) {  
    // First check to see if the object has the same amount of keys as expected
     if(Object.keys(object).length !== expectedKeys.length)
     {
       return false;
     }
     
     // Go through the expected keys array
     for(var i = 0; i < expectedKeys.length; i++)
     {
       // If the key is not found in the object's keys return false
       if(!Object.keys(object).find(function(key) {
         return key === expectedKeys[i];
       }))
       {
         return false;
       }
     }
     
     return true;
   
   }

   /**
    * Function to return an object with an owner name, a list of toDos and a function to generate an html ul
    * 
    * @param {string} owner                 The owner name of the object
    * @param {array of strings} toDos       The list of toDos of the object
    */
   function makeToDos(owner, toDos) {
    return {
      owner: owner,
      toDos: toDos,
      // Method to generate an html ul for the toDos
      generateHtml : function() {
        var final = "<ul>";
        
        for(var i = 0; i < this.toDos.length; i++)
        {
          final += "<li>" + this.toDos[i] + "</li>";
        }
        
        return final + "</ul>";
      }
    };
 }