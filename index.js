const express = require('express');
const bodyParser = require('body-parser')

const app = express();

app.use(bodyParser.json());       // to support JSON-encoded bodies
app.use(bodyParser.urlencoded({     // to support URL-encoded bodies
  extended: true
}));

app.post('/', (req, res) => {
  console.log(req.body);
  console.log(req.params);
  return res.send(req.body);
});

app.listen(8000, () => console.log('Example app listening'))
