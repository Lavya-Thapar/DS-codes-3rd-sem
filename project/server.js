const express = require('express');
const bodyParser = require('body-parser');
const mongoose = require('mongoose');

const app = express();
const port = 3000;

// Connect to your MongoDB database (replace 'your-database-name' with your actual database name)
mongoose.connect('mongodb://localhost:27017/bookstore', {
    useNewUrlParser: true,
    useUnifiedTopology: true
})
.then(() => {
    console.log('Connected to MongoDB');
})
.catch(error => {
    console.error('Error connecting to MongoDB:', error);
});

app.use(bodyParser.json());

// Define a Mongoose model and schema
const userSchema = new mongoose.Schema({
    data: String,
    createdAt: {
        type: Date,
        default: Date.now
    }
});

const User = mongoose.model('User', userSchema);

app.post('/saveData', (req, res) => {
    const userData = req.body.data;

    // Create a new user document and save it to MongoDB
    const newUser = new User({ data: userData });

    newUser.save()
        .then(() => {
            console.log('Data saved to MongoDB');
            res.json({ message: 'Data saved successfully' });
        })
        .catch(error => {
            console.error('Error saving data to MongoDB:', error);
            res.status(500).json({ error: 'Error saving data' });
        });
});

app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});
