'use strict';


/**
 * Permite obtener la lista de todas las políticas
 *
 * id String Código de la política
 * amountInsured Float Suma asegurada
 * email String Email de la política
 * inceptionDate date Fecha de inicio
 * installmentPayment Boolean Pago
 * clientId String Id cliente enlazado
 * returns List
 **/
exports.politicsGET = function(id,amountInsured,email,inceptionDate,installmentPayment,clientId) {
  return new Promise(function(resolve, reject) {
    var examples = {};
    examples['application/json'] = [ {
  "clientId" : "e8fd159b-57c4-4d36-9bd7-a59ca13057bb",
  "inceptionDate" : "2000-01-23",
  "amountInsured" : 1825.89,
  "id" : "a0ece5db-cd14-4f21-812f-966633e7be86",
  "installmentPayment" : true,
  "email" : "inesblankenship@quotezart.com"
}, {
  "clientId" : "e8fd159b-57c4-4d36-9bd7-a59ca13057bb",
  "inceptionDate" : "2000-01-23",
  "amountInsured" : 1825.89,
  "id" : "a0ece5db-cd14-4f21-812f-966633e7be86",
  "installmentPayment" : true,
  "email" : "inesblankenship@quotezart.com"
} ];
    if (Object.keys(examples).length > 0) {
      resolve(examples[Object.keys(examples)[0]]);
    } else {
      resolve();
    }
  });
}


/**
 * Borra la información de una política ingresando su ID
 *
 * id String Código de la política
 * returns String
 **/
exports.politicsIdDELETE = function(id) {
  return new Promise(function(resolve, reject) {
    var examples = {};
    examples['application/json'] = "{\"message\":\"Politics <id> deleted.\"}";
    if (Object.keys(examples).length > 0) {
      resolve(examples[Object.keys(examples)[0]]);
    } else {
      resolve();
    }
  });
}


/**
 * Obtener información de una política ingresando su ID
 *
 * id String Código de la política
 * returns List
 **/
exports.politicsIdGET = function(id) {
  return new Promise(function(resolve, reject) {
    var examples = {};
    examples['application/json'] = [ {
  "clientId" : "e8fd159b-57c4-4d36-9bd7-a59ca13057bb",
  "inceptionDate" : "2000-01-23",
  "amountInsured" : 1825.89,
  "id" : "a0ece5db-cd14-4f21-812f-966633e7be86",
  "installmentPayment" : true,
  "email" : "inesblankenship@quotezart.com"
}, {
  "clientId" : "e8fd159b-57c4-4d36-9bd7-a59ca13057bb",
  "inceptionDate" : "2000-01-23",
  "amountInsured" : 1825.89,
  "id" : "a0ece5db-cd14-4f21-812f-966633e7be86",
  "installmentPayment" : true,
  "email" : "inesblankenship@quotezart.com"
} ];
    if (Object.keys(examples).length > 0) {
      resolve(examples[Object.keys(examples)[0]]);
    } else {
      resolve();
    }
  });
}


/**
 * Permite añadir políticas en nuestra base de datos
 *
 * politics politics Crear una nueva política en la base de datos (optional)
 * returns String
 **/
exports.politicsPOST = function(politics) {
  return new Promise(function(resolve, reject) {
    var examples = {};
    examples['application/json'] = "OK";
    if (Object.keys(examples).length > 0) {
      resolve(examples[Object.keys(examples)[0]]);
    } else {
      resolve();
    }
  });
}

